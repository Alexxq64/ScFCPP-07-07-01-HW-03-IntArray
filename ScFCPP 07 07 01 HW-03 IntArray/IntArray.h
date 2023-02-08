#pragma once
#include <exception>

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
	
	//вставить элемент в контейнер;
	//удалить элемент из контейнера;
	//вставка в начало и конец;
	//поиск в контейнере элемента по значению.
};

//exception — для выхода за пределы массива — bad_range, предоставление неправильной длины массиву bad_length.

class bad_range;
class bad_length;
