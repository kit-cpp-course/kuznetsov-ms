#pragma once
#include <vector>

using namespace std;

// base class for decoding
class Decoder
{
protected:
	virtual vector<short> decode(const vector<char> & in) const = 0;
public:
	virtual vector<short> getData() = 0;
};
