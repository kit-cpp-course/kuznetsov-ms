#include "Codec.h"
#include "ALawEncoder.h"
#include "ALawDecoder.h"
#include "UseFile.h"

using namespace std;
using namespace codec;
using namespace usefile;

/*
  argv[1] - "Encode" or "Decode"
  argv[2] - path of file of source data
  argv[3] - path of file of encoded/decoded data
*/
int main(int argc, char * argv[])
{
	if (argc == 4)
	{
		bool check = true;
		string action=argv[1], pathFrom=argv[2], pathTo=argv[3];
		if (action == "Encode")
		{
			vector<int> source = UseFile::ReadPcm(pathFrom, check);
			if (check == true)
			{
				ALawEncoder ALAW(source);
				vector<char> alaw = ALAW.getData();
				UseFile::WriteFile(alaw, pathTo);
			}
		}
		if (action == "Decode")
		{
			vector<char> alaw = UseFile::ReadALaw(pathFrom, check);
			if (check == true)
			{
				ALawDecoder SOURCE(alaw);
				vector<short> source = SOURCE.getData();
				UseFile::WriteFile(source, pathTo);
			}
		}
	}
	else cout <<endl<< "exception: UNCORRECT NUMBER OF ARGUMENTS!";

	return 0;
}