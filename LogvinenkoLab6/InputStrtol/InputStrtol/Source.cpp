#include <iostream>
#include "Parser.h"
using namespace std;

int main()
{
	int res;
	res = Parser::ParseInt();
	cout << "res=" << res << endl;
	system("pause");
}


