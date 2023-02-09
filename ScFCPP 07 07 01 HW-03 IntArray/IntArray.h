#pragma once
#include <exception>
#include <iostream>
#include <iomanip>

using namespace std;

class IntArray{
	int _length;
	int* _data;
public:
	int getLength();
	//create a container;
	IntArray(int length);
	IntArray();
	~IntArray();
	//copy the container;
	IntArray(const IntArray& aFrom);
	//override tne assignment operator
	IntArray& operator=(const IntArray& a);
	//get any element by index;
	int& operator[](int index);
	//change the container length;
	void resize(int length);
	//insert an element to the container;
	void insert(int elem, int index);
	//remove and return an element from the container;
	int remove(int index);
	//insert to the begining and to the end;
	void pushFirst(int elem);
	void pushLast(int elem);
	//remove and return first and last element;
	int pullFirst();
	int pullLast();
	//look for an element by the value
	int find(int elem);
	bool findAll(int elem);
	void printIntArray(string name);
};

//exception: for out of the array bounds — bad_range; for the wrong array length - bad_length.

class bad_range : public exception {
public:
	const char* what() const noexcept override;
};

class bad_length : public exception {
public:
	const char* what() const noexcept override;
};
