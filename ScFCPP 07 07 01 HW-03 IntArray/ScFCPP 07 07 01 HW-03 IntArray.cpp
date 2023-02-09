#include "IntArray.h"
#include <chrono>
#include <vector>


int main()
{
	try {
		// Declare an array with 10 elements 0 by default
		IntArray a;

		// output an element to console
		// to make an error put number less than 0 or more than 9
		cout << a[9] << endl;

		// Fill the array with numbers from 1 to 10
		// to make an error put number more than 10 instead of a.getLength()
		for (int i = 0; i < a.getLength(); ++i)
			a[i] = i + 1;

		// Resize the array to 12 elements
		// to make an error put number less than 1
		int n = 12;
		a.resize(n);
		cout << a[0] << endl;

		// now there are 12 elements
		// Insert the number 10 to the position 12
		// 0 - before first element, 12 - after last element 
		// to make an error put number less than 0 or more than 12 instead of 12
		a.insert(10, 12);

		// now there are 13 elements
		// Remove the element with index 3
		// to make an error put number less than 0 or more than 12
		a.remove(3);

		// now there are 12 elements
		// pushLast 30 and 40 to the end and to the beginning
		a.pushLast(30);
		a.pushFirst(40);

		// now there are 14 elements
		// find an element
		int number = 10;
		int pos = a.find(number);
		if (pos >= 0)
			cout << "First occurrence of number " << number << " is at the position " << pos << endl;
		else
			cout << "There is no number " << number << " in this IntArray." << endl;
		// find all occurrences
		a.findAll(number);

		// A few more tests to ensure copy constructing / assigning arrays
		// doesn't break things
		IntArray b(a);
		IntArray d = a;
		b = b;
		a = a;

		// Print out all the numbers
		a.printIntArray("a");
		b[3] = 100;
		b.printIntArray("b");
		d.pushLast(99);
		d.printIntArray("d");


		// execution speed comparison: IntArray vs vector
		int aLot = 1000000;
		int size = 14;

		vector <int> v(size);

		// delete and restore first element many times
		auto start = chrono::high_resolution_clock::now();
		for (int i = 0; i < aLot; i++) {
			v.pop_back();
			v.push_back(10);
		}
		cout << "Delete and restore last element many times.\n";
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
		cout << "Delete and restore first element many times.\n";
		cout << "Passed " << (chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count())/1000 << " ms.\n";
		cout << "Vector v:   ";
		for (int i = 0; i < size; ++i)
			cout << setw(4) << v[i] << ' ';
		cout << "\n\n";


		// delete and restore first element many times
		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < aLot; i++) {
			a.pullFirst();
			a.pushFirst(10);
		}
		cout << "Delete and restore first element many times.\n";
		cout << "Passed " << (chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count())/1000 << " ms.\n";
		a.printIntArray("a");

		// delete and restore last element many times
		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < aLot; i++) {
			a.pullLast();
			a.pushLast(11);
		}
		cout << "Delete and restore last element many times.\n";
		cout << "Passed " << (chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count()) / 1000 << " ms.\n";
		a.printIntArray("a");

		// delete and restore fifth element many times
		start = chrono::high_resolution_clock::now();
		for (int i = 0; i < aLot; i++) {
			a.remove(5);
			a.insert(15, 5);
		}
		cout << "Delete and restore fifth element many times.\n";
		cout << "Passed " << (chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() - start).count()) / 1000 << " ms.\n";
		a.printIntArray("a");


	}
	catch (exception& e) {
		cout << e.what();
	}

	return 0;
}