#pragma once
#include "Encoder.h"

// child class for encoding pcm to 8-bit according to a-law
class ALawEncoder :public Encoder
{
private:
	vector<char> alaw; // it contains encoding data
	vector<char> encode(const vector<int> & pcm) const;
	char PCM2ALAW(int pcm) const; // an algorithm of encoding
	vector<char> getData(); // it returns vector of chars
public:
	ALawEncoder(const vector<int> & pcm) :alaw(encode(pcm)) {} // constructor
};