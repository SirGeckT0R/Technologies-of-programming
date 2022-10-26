#pragma once

class FractionException
{
private:
	char str[200];
public:
	FractionException(const char* str);
	const char* what();
};

