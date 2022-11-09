#include "ListIOHelper.h"

List ListIOHelper::listFromFile(string filename) {
		List list;
		ifstream fin;
		fin.open(filename);
		if (!fin.is_open()) {
			cout << ("Can't open file with name: " + filename) << endl;
			return list;
		}

		double value = 0;
		while (!fin.eof()) {
			fin >> value;
			list.addLast(value);
		}
		fin.close();
		return list;
}

void ListIOHelper::listToFile(string filename, List list) {
	ofstream fout;
	fout.open(filename, ofstream::app);
	if (!fout.is_open()) {
		cout << ("Can't open file with name: " + filename) << endl;
		return;
	}

	fout << list.toString();
	fout.close();
}
List ListIOHelper::listFromConsole(int size) {
	List list;
	double value;
	for (int i = 0; i < size; i++) {
		cout << "Enter element of a list:";
		cin >> value;
		list.addLast(value);
	}
	return list;
}