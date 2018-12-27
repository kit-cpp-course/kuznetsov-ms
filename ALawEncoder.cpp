#include "ALawEncoder.h"

vector<char> ALawEncoder::encode(const vector<int> & pcm) const
{
	vector<char> out;
	for (int el : pcm) out.push_back(PCM2ALAW(el));
	return out;
}

char ALawEncoder::PCM2ALAW(int pcm) const
{
	short MAX = 0x7fff;
	int sign = (pcm & 0x8000) >> 8;
	if (sign != 0)
		pcm = -pcm;
	if (pcm > MAX) pcm = MAX;
	int exponent = 7;
	for (int expMask = 0x4000; (pcm & expMask) == 0
		&& exponent > 0; exponent--, expMask >>= 1) {
	}
	int mantissa = (pcm >> ((exponent == 0) ? 4 : (exponent + 3))) & 0x0f;
	char alaw = (char)(sign | exponent << 4 | mantissa);
	return (char)(alaw ^ 0xD5);
}

vector<char> ALawEncoder::getData()
{ 
	return ALawEncoder::alaw;
}