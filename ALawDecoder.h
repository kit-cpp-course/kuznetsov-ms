#pragma once
#include "Decoder.h"

// a child class for decoding from 8-bit to pcm according to a-law
class ALawDecoder :public Decoder
{
private:
	vector<short> pcm; // it contains pcm data
	vector<short> decode(const vector<char> & alaw) const;
	short ALAW2PCM(char alaw) const; // an algorithm of decoding
	vector<short> getData(); // it returns vector of shorts
public:
	ALawDecoder(const vector<char> & alaw) :pcm(decode(alaw)) {} // construstor
};