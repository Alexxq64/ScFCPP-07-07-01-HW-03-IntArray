#pragma once
#include <exception>

using namespace std;

class IntArray{
	int _length;
	int* _data;
public:
	int getLength();
	//������� ���������;
	IntArray(int length);
	IntArray();
	~IntArray();
	//����������� ���������;
	IntArray(const IntArray& aFrom);
	//�������� ������ � ������ �������� ���������� �� �������;
	int& operator[](int index);
	//�������� ������ ����������;
	
	//�������� ������� � ���������;
	//������� ������� �� ����������;
	//������� � ������ � �����;
	//����� � ���������� �������� �� ��������.
};

//exception � ��� ������ �� ������� ������� � bad_range, �������������� ������������ ����� ������� bad_length.

class bad_range;
class bad_length;
