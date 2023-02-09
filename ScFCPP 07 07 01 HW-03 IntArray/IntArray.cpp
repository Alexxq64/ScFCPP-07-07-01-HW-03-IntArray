#include "IntArray.h"

int IntArray::getLength(){
	return _length;
}

IntArray::IntArray(int length) : _length(length) {
	if (length < 0) throw bad_length();
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
	if (index < 0 || index >= _length) throw bad_range();
	return _data[index];
}

void IntArray::resize(int length){
	if (length < 0) throw bad_length();
	int* temp = new int[length];
	for (int i = 0; i < length; i++) 
		temp[i] = (i < _length) ? _data[i] : 0;
	delete[] _data;
	_data = temp;
	_length = length;
}

void IntArray::insert(int elem, int index){
	if (index < 0 || index > _length) throw bad_range();
	resize(_length + 1);
	for (int i = _length - 1; i > index; i--)
		_data[i] = _data[i - 1];
	_data[index] = elem;
}

void IntArray::remove(int index){
	for (int i = index; i < _length - 1; i++)
		_data[i] = _data[i + 1];
	resize(_length - 1);
}

void IntArray::push(int elem){
	insert(elem, 0);
}

void IntArray::add(int elem){
	insert(elem, _length);
}

int IntArray::find(int elem){
	for (int i = 0; i < _length; i++)
		if (_data[i] == elem) return i;
	return -1;
}

bool IntArray::findAll(int elem){
	int contains = 0;
	for (int i = 0; i < _length; i++) {
		if (_data[i] == elem) {
			cout << "There is element " << elem << " at the position " << i << endl;
			contains++;
		}
	}
	cout << "Total occurrences of element " << elem << ": " << contains << endl;
	return (contains > 0) ? true : false ;
}

//class bad_range : public exception {
//public:
//	const char* what() const noexcept override { return "Out of range.\n"; }
//};

//class bad_length : public exception {
//public:
//	const char* what() const noexcept override { return "Wrong length.\n"; }
//};