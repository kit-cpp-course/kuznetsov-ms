#include "UseFile.h"

namespace usefile
{
	// It returns integer data vector from file
	vector<int> UseFile::ReadPcm(string & path, bool & check)
	{
		vector<int> data;
		string line;
		ifstream in(path);
		if (in.is_open())
		{
			while (getline(in, line))
			{
				for (int i=0;i<line.length();i++)
				{
					if ((i==0 && !isdigit(line[0]) && line[0]!='-')||(i!=0 && !isdigit(line[i])))
					{
						check = false;
						break;
					}
				}
				if (check == false)
				{
					cout << "exception: UNCORRECT TYPE OF DATA!";
					break;
				}
				data.push_back(atoi(line.c_str()));
			}
		}
		else
		{
			cout << "exception: UNCORRECT PATH!";
			check = false;
		}
		in.close();
		return data;
	}

	// It returns char data vector from file
	vector<char> UseFile::ReadALaw(string & path, bool & check)
	{
		vector<char> data;
		string line;
		ifstream in(path);
		if (in.is_open())
		{
			while (getline(in, line))
			{
				if (line.length() > 1)
				{
					for (short i = 0; i < line.length(); i++)
					{
						if ((!isdigit(line[i]) && i != 0) || (i == 0 && !isdigit(line[i]) && line[i] != '-'))
						{
							check = false;
							break;
						}
					}
					if (check==true) if (atoi(line.c_str()) < CHAR_MIN || atoi(line.c_str()) > CHAR_MAX) check = false;
					if (check == false)
					{
						cout << "exception: UNCORRECT TYPE OF DATA!";
						break;
					}
					data.push_back(atoi(line.c_str()));
				}
				if (line.length() == 1) data.push_back(line[0]);
			}
		}
		else
		{
			cout << "exception: UNCORRECT PATH!";
			check = false;
		}
		in.close();
		return data;
	}

	// It write short data vector to file
	void UseFile::WriteFile(vector<short> & data, string & path)
	{
		ofstream out(path, ios::app);
		if (out.is_open())
		{
			for (short i:data) out << i << std::endl;
		}
		out.close();
	}

	// It write char data vector to file
	void UseFile::WriteFile(vector<char> & data, string & path)
	{
		ofstream out(path, ios::app);
		if (out.is_open())
		{
			for (char i : data) out << i << std::endl;
		}
		out.close();
	}
}