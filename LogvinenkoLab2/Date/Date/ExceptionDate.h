#ifndef EXCEPTIONDATE_H
#define EXCEPTIONDATE_H

class ExceptionDate
{
private:
	char str[200];
public:
	ExceptionDate(const char* str);
	const char* what();
};


#endif