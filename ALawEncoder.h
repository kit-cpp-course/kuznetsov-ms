#pragma once
#include "Codec.h"

namespace codec
{
	// Child class. It encodes source pcm data to alaw data
	class ALawEncoder :public Data<char>
	{
	private:
		static char PcmToAlaw(int & pcm); // A-Law encoding algorithm: PCM(16-bit) to ALAW(8-bit)
		static vector<char> encode(vector<int> & pcm); // It returns a data vector of encoding (PCM to ALAW)
	public:
		ALawEncoder(vector<int> & pcm); // Constructor
	};
}