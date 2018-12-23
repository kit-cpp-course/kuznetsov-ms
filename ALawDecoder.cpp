#include "ALawDecoder.h"

namespace codec
{
	// A-Law decoding algorithm: ALAW(8-bit) to PCM(16-bit)
	short ALawDecoder::ALawToPcm(char & alaw)
	{
		alaw ^= 0xD5;
		int sign = alaw & 0x80;
		int exponent = (alaw & 0x70) >> 4;
		int data = alaw & 0x0f;
		data <<= 4;
		data += 8;
		if (exponent != 0) data += 0x100;
		if (exponent > 1) data <<= (exponent - 1);
		return (short)(sign == 0 ? data : -data);
	}

	// It returns a data vector of decoding (ALAW to PCM)
	vector<short> ALawDecoder::decode(vector<char> & alaw)
	{
		vector<short> pcm;
		for (int i = 0; i < alaw.size(); i++) pcm.push_back(ALawToPcm(alaw[i]));
		return pcm;
	}

	// Constructor
	ALawDecoder::ALawDecoder(vector<char> & alaw) :Data(decode(alaw)) { }
}
