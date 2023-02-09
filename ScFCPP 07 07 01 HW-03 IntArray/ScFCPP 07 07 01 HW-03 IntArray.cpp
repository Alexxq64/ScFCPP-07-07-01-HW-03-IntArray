#include "IntArray.h"
#include <chrono>
#include <vector>


int main()
{
	try {
		// TEST
		// Declares an array with 10 elements 0 by default
		IntArray a;

		// to make an error put number less than 0 or more than 9
		// outputs an element to console
		cout << a[9] << endl;

		// to make an error put number more than 10 instead of a.getLength()
		// Fills the array with numbers from 1 to 10
		for (int i = 0; i < a.getLength(); ++i)
			a[i] = i + 1;

		// to make an error put number less than 1
		// Resizes the array to 12 elements
		int n = 12;
		a.resize(n);
		cout << a[0] << endl;

		// now there are 12 elements and 13 positions to insert new element
		// to make an error put number less than 0 or more than 12 instead of 12
		// 0 - before first element, 12 - after last element 
		// Inserts the number 10 to the position 12
		a.insert(10, 12);

		// now there are 13 elements
		// to make an error put number less than 0 or more than 12
		// Removes the element with index 3
		a.remove(3);

		// now there are 12 elements
		// pushes 30 and 40 to the end and to the beginning
		a.pushLast(30);
		a.pushFirst(40);

		// now there are 14 elements
		// finds an element
		int number = 10;
		int pos = a.find(number);
		if (pos >= 0)
			cout << "First occurrence of number " << number << " is at the position " << pos << endl;
		else
			cout << "There is no number " << number << " in this IntArray." << endl;
		// finds all occurrences
		a.findAll(number);

		// A few more tests to ensure copy constructing / assigning arrays
		// doesn't break things
		IntArray b(a);
		IntArray d = a;
		b = b;
		a = a;

		// Prints out all the numbers
		a.printIntArray("a");
		b[3] = 100;
		b.printIntArray("b");
		d.pushLast(99);
		d.printIntArray("d");


		// Execution speed comparison: IntArray vs vector
		// just out of interes
		int aLot = 1000000;
		int size = a.getLength();

		vector <int> v(size);

		// deletes and restores last element many times
		auto start = chrono::high_resolution_clock::now();
		for (int i = 0; i < aLot; i++) {
			v.pop_back();
			v.push_back(10);
		}
		cout << "Deletes and restores last element many times.\n";
		cout << "Passed " << (chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count())/1000 << " ms.\n";
		cout << "Vector v:   ";
		for (int i = 0; i < size; ++i)
			cout << setw(4) << v[i] << ' ';
		cout << "\n\n";

		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < aLot; i++) {
			v.erase(v.begin());
			v.insert(v.begin(), 27);
		}
		cout << "Deletes and restores first element many times.\n";
		cout << "Passed " << (chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count())/1000 << " ms.\n";
		cout << "Vector v:   ";
		for (int i = 0; i < size; ++i)
			cout << setw(4) << v[i] << ' ';
		cout << "\n\n";


		// deletes and restores first element many times
		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < aLot; i++) {
			a.pullFirst();
			a.pushFirst(10);
		}
		cout << "Deletes and restores first element many times.\n";
		cout << "Passed " << (chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count())/1000 << " ms.\n";
		a.printIntArray("a");

		// deletes and restores last element many times
		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < aLot; i++) {
			a.pullLast();
			a.pushLast(11);
		}
		cout << "Deletes and restores last element many times.\n";
		cout << "Passed " << (chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count()) / 1000 << " ms.\n";
		a.printIntArray("a");

		// deletes and restores fifth element many times
		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < aLot; i++) {
			a.remove(5);
			a.insert(15, 5);
		}
		cout << "Deletes and restores fifth element many times.\n";
		cout << "Passed " << (chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count()) / 1000 << " ms.\n";
		a.printIntArray("a");


	}
	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}