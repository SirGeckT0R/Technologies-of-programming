#pragma once
#include <iostream>
#include <list>
#include <fstream>
using namespace std;
class ListIOHelper {
public:
	static list<double> listFromFile(string filename);
	static void listToFile(string filename, list<double> list);
	static list<double> listFromConsole(int size);
};