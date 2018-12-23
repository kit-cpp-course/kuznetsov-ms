#pragma once
#include <vector>
#include <ostream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

namespace usefile
{
	// A class without fields. It's needed only for using methods of reading data from file and writing data to file
	class UseFile
	{
	public:
		static vector<int> ReadPcm(string & path,bool & check); // It returns integer data vector from file
		static vector<char> ReadALaw(string & path, bool & check); // It returns char data vector from file
		static void WriteFile(vector<short> & data, string & path); // It write short data vector to file
		static void WriteFile(vector<char> & data, string & path); // It write char data vector to file
	};
}