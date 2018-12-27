#pragma once
#include <vector>

using namespace std;

// base class for encoding
class Encoder
{
protected:
	virtual vector<char> encode(const vector<int> & pcm) const = 0;
public:
	virtual vector<char> getData() = 0;
};