#include "ALawDecoder.h"

vector<short> ALawDecoder::decode(const vector<char> & alaw) const
{
	vector<short> out;
	for (char el : alaw) out.push_back(ALAW2PCM(el));
	return out;
}

short ALawDecoder::ALAW2PCM(char alaw) const
{
	alaw ^= 0xD5;
	int sign = alaw & 0x80;
	int exponent = (alaw & 0x70) >> 4;
	int data = alaw & 0x0f;
	data <<= 4;
	data += 8;
	if (exponent != 0)
		data += 0x100;
	if (exponent > 1)
		data <<= (exponent - 1);
	return (short)(sign == 0 ? data : -data);
}

vector<short> ALawDecoder::getData()
{
	return ALawDecoder::pcm;
}