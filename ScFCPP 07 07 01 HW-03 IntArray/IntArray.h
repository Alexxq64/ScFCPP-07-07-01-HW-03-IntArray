#pragma once
#include <exception>
#include <iostream>

using namespace std;

class IntArray{
	int _length;
	int* _data;
public:
	int getLength();
	//создать контейнер;
	IntArray(int length);
	IntArray();
	~IntArray();
	//скопировать контейнер;
	IntArray(const IntArray& aFrom);
	//получить доступ к любому элементу контейнера по индексу;
	int& operator[](int index);
	//изменить размер контейнера;
	void resize(int length);
	//вставить элемент в контейнер;
	void insert(int elem, int index);
	//удалить элемент из контейнера;
	void remove(int index);
	//вставка в начало и конец;
	void puch(int elem);
	void add(int elem);
	//поиск в контейнере элемента по значению.
	int find(int elem);
	bool findAll(int elem);
};

//exception — для выхода за пределы массива — bad_range, предоставление неправильной длины массиву bad_length.

class bad_range : public exception {
public:
	const char* what() const noexcept override { return "Out of range.\n"; }
};

class bad_length : public exception {
public:
	const char* what() const noexcept override { return "Wrong length.\n"; }
};

class bad_range{};
//class bad_length;
