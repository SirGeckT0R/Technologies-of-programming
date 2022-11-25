#pragma once
#include<stdexcept>//for class runtime_error and class exception
using namespace std;//using std::exception;
//Класс exception является стандартным 
//базовым классом C++ для всех исключений. 
//Типичный класс исключения, производный от exception,
//определяет только конструктор, 
//который передает конструктору базового
//класса exception строку с сообщением об ошибке.
//Любой класс исключения, прямо или косвенно наследующий
//от exception, содержит виртуальную

//функцию what, которая возвращает сообщение об ошибке
//объекта исключения.

class ExeptoinPublishYear : public exception
{
public:
	ExeptoinPublishYear(char const* const Message);
	~ExeptoinPublishYear();
};

