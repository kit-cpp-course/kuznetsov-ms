#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <ostream>
#include <fstream>

using namespace std;

namespace codec
{
	// Base class
	template <typename TypeTo> class Data
	{
	private:
		vector<TypeTo> data; // Data vector of encoded/decoded data
	protected:
		Data(vector<TypeTo> DataTo) :data(DataTo) {} // Constructor
	public:
		vector<TypeTo> getData() { return data; } // It returns data vector
		TypeTo getData(short ind) { return data[ind]; } // It returns an element from data vector according to index
	};
}