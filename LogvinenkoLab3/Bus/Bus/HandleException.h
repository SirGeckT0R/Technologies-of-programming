#pragma once

class HandleException
{
private:
	char str[200];
public:
	HandleException(const char* str);
	const char* what();
};

