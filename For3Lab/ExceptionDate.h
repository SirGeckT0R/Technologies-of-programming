#pragma once

class ExceptionDate
{
private:
	char str[200];
public:
	ExceptionDate(const char* str);
	const char* what();
};

