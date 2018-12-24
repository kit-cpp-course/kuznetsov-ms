#pragma once
#include "Codec.h"

namespace codec
{
	// Child class. It decodes alaw data to pcm data
	class ALawDecoder :public Data<short>
	{
	private:
		static short ALawToPcm(char & alaw); // A-Law decoding algorithm: ALAW(8-bit) to PCM(16-bit)
		static vector<short> decode(vector<char> & alaw); // It returns a data vector of decoding (ALAW to PCM)
	public:
		ALawDecoder(vector<char> & alaw); // Constructor
	};
}