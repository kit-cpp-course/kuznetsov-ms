#include "Encoder.h"
#include "Decoder.h"
#include "ALawEncoder.h"
#include "ALawDecoder.h"
#include "UseFile.h"

// User should write:
// as a 1st argument: [Path to ALawCompression.exe file]
// next arguments user may write as user want
// for action: act Encode/Decode
// for input file: in [Path to input file]
// for output file (it will be created): out [Path to output file]

int main(int argc,char* argv[])
{
	bool check = true;
	string act="", in="", out="";
	try
	{
		if (argc<7) throw "exception: NOT ENOUGH INPUT ARGUMENTS OR FLAGS!";
		if (argc>7) throw "exception: TOO MANY INPUT ARGUMENTS OR FLAGS!";
		for (short i = 0; i < 6; i++)
		{
			string flag = argv[i];
			if (flag == "act")
			{
				act = argv[i + 1];
			}
			else
			{
				if (flag == "in")
				{
					in = argv[i + 1];
				}
				else
				{
					if (flag == "out")
					{
						out = argv[i + 1];
					}
				}
			}
		}
		if (act == "" || in == "" || out == "") throw "exception: NOT ENOUGH INPUT ARGUMENTS OR FLAGS!";
		if (act == "Encode")
		{
			vector<int> pcm = ReadPcm(in, check);
			if (check == true)
			{
				Encoder *alaw[1];
				alaw[0] = new ALawEncoder(pcm);
				vector<char> get_alaw = alaw[0]->getData();
				WriteFile(get_alaw,out);
			}
		}
		else
		{
			if (act == "Decode")
			{
				vector<char> alaw = ReadALaw(in, check);
				if (check == true)
				{
					Decoder * pcm[1];
					pcm[0] = new ALawDecoder(alaw);
					vector<short> get_pcm = pcm[0]->getData();
					WriteFile(get_pcm, out);
				}
			}
			else throw "exception: UNCORRECT ARGUMENT OF ACTION!";
		}
	}
	catch (const char* ex)
	{
		cout << ex;
	}
	catch (const std::exception&error)
	{
		cout << "exception: ERROR!";
	}
	return 0;
}