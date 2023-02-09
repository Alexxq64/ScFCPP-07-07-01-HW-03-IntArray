#pragma once
#include <exception>
#include <iostream>

using namespace std;

class IntArray{
	int _length;
	int* _data;
public:
	int getLength();
	//ᮧ���� ���⥩���;
	IntArray(int length);
	IntArray();
	~IntArray();
	//᪮��஢��� ���⥩���;
	IntArray(const IntArray& aFrom);
	//������� ����� � ��� ������ ���⥩��� �� �������;
	int& operator[](int index);
	//�������� ࠧ��� ���⥩���;
	void resize(int length);
	//��⠢��� ����� � ���⥩���;
	void insert(int elem, int index);
	//㤠���� ����� �� ���⥩���;
	void remove(int index);
	//��⠢�� � ��砫� � �����;
	void push(int elem);
	void add(int elem);
	//���� � ���⥩��� ����� �� ���祭��.
	int find(int elem);
	bool findAll(int elem);
};

//exception ? ��� ��室� �� �।��� ���ᨢ� ? bad_range, �।��⠢����� ���ࠢ��쭮� ����� ���ᨢ� bad_length.

class bad_range : public exception {
public:
	const char* what() const noexcept override { return "Out of range.\n"; }
};

class bad_length : public exception {
public:
	const char* what() const noexcept override { return "Wrong length.\n"; }
};

//class bad_range{
//public:
//	const char* what();
//};
//class bad_length;
