#pragma once

class Exception
{
private:
	char str[200];
public:
	Exception(const char* str);
	const char* what();
};

