#include "ListIOHelper.h"
#include "ListHandler.h"
list<double> ListIOHelper::listFromFile(string filename) {
		list<double> list;
		ifstream fin;
		fin.open(filename);
		if (!fin.is_open()) {
			cout << ("Can't open file with name: " + filename) << endl;
			return list;
		}

		double value = 0;
		while (!fin.eof()) {
			fin >> value;
			list.push_back(value);
		}
		fin.close();
		return list;
}

void ListIOHelper::listToFile(string filename, list<double>  list) {
	ofstream fout;
	fout.open(filename, ofstream::app);
	if (!fout.is_open()) {
		cout << ("Can't open file with name: " + filename) << endl;
		return;
	}

	fout << ListHandler::toString(list);
	fout.close();
}
list<double> ListIOHelper::listFromConsole(int size) {
	list<double> list;
	double value;
	for (int i = 0; i < size; i++) {
		cout << "Enter element of a list:";
		cin >> value;
		list.push_back(value);
	}
	return list;
}