#pragma once
#include <vector>
#include <ostream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

vector<int> ReadPcm(string & path,bool & check); // It returns integer data vector from file
vector<char> ReadALaw(string & path, bool & check); // It returns char data vector from file
void WriteFile(vector<short> & data, string & path); // It write short data vector to file
void WriteFile(vector<char> & data, string & path); // It write char data vector to file