#include "ALawEncoder.h"

namespace codec
{
	// A-Law encoding algorithm: PCM(16-bit) to ALAW(8-bit)
	char ALawEncoder::PcmToAlaw(int & pcm)
	{
		const int MAX = 0x7fff;
		int sign;
		if (pcm < 0 && pcm < -MAX)
		{
			pcm = -MAX;
			sign = (pcm & 0x8000) >> 8;
		}
		else if (pcm > 0 && pcm > MAX)
		{
			pcm = MAX;
			sign = (pcm & 0x8000) >> 8;
		}
		sign = (pcm & 0x8000) >> 8;
		if (pcm < 0) pcm = -pcm;
		int exponent = 7;
		for (int expMask = 0x4000; (pcm & expMask) == 0 && exponent > 0; exponent--, expMask >>= 1) {}
		int mantissa = (pcm >> ((exponent == 0) ? 4 : (exponent + 3))) & 0x0f;
		char alaw = (char)(sign | exponent << 4 | mantissa);
		return (char)(alaw ^ 0xD5);
	}
	
	// It returns a data vector of encoding (PCM to ALAW)
	vector<char> ALawEncoder::encode(vector<int> & pcm)
	{
		vector<char> alaw;
		for (int i = 0; i < pcm.size(); i++) alaw.push_back(PcmToAlaw(pcm[i]));
		return alaw;
	}

	// Constructor
	ALawEncoder::ALawEncoder(vector<int> & pcm) : Data(encode(pcm)) {}
}