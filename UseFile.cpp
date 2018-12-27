#include "UseFile.h"

	// It returns integer data vector from file
	vector<int> ReadPcm(string & path, bool & check)
	{
		vector<int> data;
		string line;
		ifstream in(path);
		try
		{
			if (in.is_open())
			{
				while (getline(in, line))
				{
					for (int i = 0; i < line.length(); i++)
					{
						if ((i == 0 && !isdigit(line[0]) && line[0] != '-') || (i != 0 && !isdigit(line[i])))
						{
							throw "exception: UNCORRECT TYPE OF DATA!";
						}
					}
					data.push_back(atoi(line.c_str()));
				}
				in.close();
			}
			else throw "exception: UNCORRECT PATH!";
		}
		catch (const char* ex)
		{
			cout << ex;
			check = false;
		}
		catch (const std::exception&error)
		{
			cout << "exception: ERROR!";
		}
		return data;
	}

	// It returns char data vector from file
	vector<char> ReadALaw(string & path, bool & check)
	{
		vector<char> data;
		string line;
		ifstream in(path);
		try
		{
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
								throw "exception: UNCORRECT TYPE OF DATA!";
							}
						}
						if (atoi(line.c_str()) < CHAR_MIN || atoi(line.c_str()) > CHAR_MAX) throw "exception: UNCORRECT TYPE OF DATA!";
						data.push_back(atoi(line.c_str()));
					}
					if (line.length() == 1) data.push_back(line[0]);
				}
			}
			else throw "exception: UNCORRECT PATH!";
			in.close();
		}
		catch (const char* ex)
		{
			cout << ex;
			check = false;
		}
		catch (const std::exception&error)
		{
			cout << "exception: ERROR!";
		}
		return data;
	}

	// It write short data vector to file
	void WriteFile(vector<short> & data, string & path)
	{
		ofstream out(path, ios::app);
		if (out.is_open())
		{
			for (short i:data) out << i << std::endl;
		}
		out.close();
	}

	// It write char data vector to file
	void WriteFile(vector<char> & data, string & path)
	{
		ofstream out(path, ios::app);
		if (out.is_open())
		{
			for (char i : data) out << i << std::endl;
		}
		out.close();
	}