#pragma once
#include<stdexcept>//for class runtime_error and class exception
using namespace std;//using std::exception;
//����� exception �������� ����������� 
//������� ������� C++ ��� ���� ����������. 
//�������� ����� ����������, ����������� �� exception,
//���������� ������ �����������, 
//������� �������� ������������ ��������
//������ exception ������ � ���������� �� ������.
//����� ����� ����������, ����� ��� �������� �����������
//�� exception, �������� �����������

//������� what, ������� ���������� ��������� �� ������
//������� ����������.

class ExeptoinPublishYear : public exception
{
public:
	ExeptoinPublishYear(char const* const Message);
	~ExeptoinPublishYear();
};

