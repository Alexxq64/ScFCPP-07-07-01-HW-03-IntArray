#include "IntArray.h"


int main()
{
    try {
    // Declare an array with 10 elements
    IntArray array(10);

    // Fill the array with numbers 1 through 10
    for (int i = 0 ; i < 10; ++i)
        array[i] = i + 1;

    // Resize the array to 8 elements
    array.resize(12);

    // Insert the number 20 before element with index 5
    array.insert(20, 12);

    // Remove the element with index 3
    array.remove(3);

    // add 30 and 40 to the end and beginning
    array.add(30);
    array.push(5);

    // find element
    int number = 25;
    int pos = array.find(number);
    if (pos >= 0)
        cout << "First occurrence of element " << number << " is at the position " << pos << endl;

    // find all occurrences
    array.findAll(number);

    // A few more tests to ensure copy constructing / assigning arrays
    // doesn't break things
        IntArray b(array);
        //b = array;
        //b = b;
        //array = array;

    // Print out all the numbers
    for (int i = 0; i < array.getLength(); ++i)
        cout << array[i] << ' ';
    cout << '\n';
    //b = array;
    b[3] = 100;
    for (int i = 0; i < b.getLength(); ++i)
        cout << b[i] << ' ';
    cout << '\n';
    }
    catch (exception& e) {
        cout << e.what();
    }

    return 0;
}