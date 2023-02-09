#include "IntArray.h"

int IntArray::getLength(){
	return _length;
}

IntArray::IntArray(int length) : _length(length) {
	if (length < 0) throw bad_length();
	_data = new int[length]{0};
}

IntArray::IntArray() : IntArray::IntArray(10) {};

IntArray::~IntArray() {
	delete[] _data;
}

IntArray::IntArray(const IntArray& aFrom){
	_length = aFrom._length;
	_data = new int[_length];
	for (int i = 0; i < _length;i++) 
		_data[i] = aFrom._data[i];
}

IntArray& IntArray::operator=(const IntArray& aFrom){
	if (&aFrom == this) return *this;
	_length = aFrom._length;
	_data = new int[_length];
	for (int i = 0; i < _length; i++)
		_data[i] = aFrom._data[i];
	return *this;
}

int& IntArray::operator[](int index){
	if (index < 0 || index >= _length) throw bad_range();
	return _data[index];
}

void IntArray::resize(int length){
	if (length < 0) throw bad_length();
	int* temp = new int[length];
	// if the array is shortened, the remainder is lost
	// if it is extended, extra elements are filled with 0
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

int IntArray::remove(int index){
	if (index < 0 || index > _length - 1) throw bad_range();
	int temp = _data[index];
	for (int i = index; i < _length - 1; i++)
		_data[i] = _data[i + 1];
	resize(_length - 1);
	return temp;
}

void IntArray::pushFirst(int elem){
	insert(elem, 0);
}

void IntArray::pushLast(int elem){
	insert(elem, _length);
}

int IntArray::pullFirst(){
	return remove(0);
}

int IntArray::pullLast(){
	return remove(_length - 1);
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
			cout << "There is element " << elem << " at the position " << i << "\n";
			contains++;
		}
	}
	cout << "Total occurrences of element " << elem << ": " << contains << "\n\n";
	return (contains > 0) ? true : false ;
}

void IntArray::printIntArray(string name){
	cout << "IntArray " <<  name << ": ";
	for (int i = 0; i < _length; ++i)
		cout << setw(4) << _data[i] << ' ';
	cout << "\n\n";
}

const char* bad_range::what() const noexcept { return "Out of range.\n"; }
const char* bad_length::what() const noexcept { return "Wrong length.\n"; }
