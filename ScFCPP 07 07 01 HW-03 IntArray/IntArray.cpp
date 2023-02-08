#include "IntArray.h"

int IntArray::getLength(){
	return _length;
}

IntArray::IntArray(int length) : _length(length) {
	_data = new int[length];
}
IntArray::IntArray() : IntArray::IntArray(10) {};
IntArray::~IntArray() {
	delete[] _data;
}

IntArray::IntArray(const IntArray& aFrom){
	_length = aFrom._length;
	_data = new int[_length];
	for (int i = 0; i < _length;i++) {
		_data[i] = aFrom._data[i];
	}
}

int& IntArray::operator[](int index){
	return _data[index];
}

class bad_range : public exception {
public:
	const char* what() const noexcept override { return "Out of range."; }
};

class bad_length : public exception {
public:
	const char* what() const noexcept override { return "Wrong length."; }
};