#pragma once
#include <iostream>
#include <fstream>
#include "./List.h"
using namespace std;
class ListIOHelper {
public:
	static List listFromFile(string filename);
	static void listToFile(string filename, List list);
	static List listFromConsole(int size);
};