// TO DO: Implement the driver main() function to test your code.
#include <iostream>
#include <string>
#include "LinkedList.hpp"

using namespace std;

int main()
{
    cout << "INT DATATYPE" << endl;
    LinkedList<int> intList;

    cout << "\nappend(10), append(20), append(30)" << endl;
    intList.append(10);
    intList.append(20);
    intList.append(30);
    cout << intList;

    cout << "\ninsert(1, 15)" << endl;
    intList.insert(1, 15);
    cout << intList;

    cout << "\nreplace(2, 99)" << endl;
    intList.replace(2, 99);
    cout << intList;

    cout << "\ngetElement(1)" << endl;
    cout << "Result: " << intList.getElement(1) << endl;

    cout << "\nremove(0)" << endl;
    intList.remove(0);
    cout << intList;

    cout << "\nEXCEPTION TEST: getElement(100)" << endl;
    try {
        intList.getElement(100);
    } catch (string&s ) {
        cout << s << endl;
    }

    cout << "\nclear()" << endl;
    intList.clear();
    cout << intList;
    cout << "Length: " << intList.getLength() << endl;

    cout << "\nEXCEPTION TEST: remove(0) on empty list" << endl;
    try {
        intList.remove(0);
    } catch (string& s) {
        cout << s << endl;
    }

    cout << "\nDOUBLE DATATYPE" << endl;
    LinkedList<double> doubleList;

    cout << "\nappend(1.1), append(2.2), append(3.3)" << endl;
    doubleList.append(1.1);
    doubleList.append(2.2);
    doubleList.append(3.3);
    cout << doubleList;

    cout << "\ninsert(2, 9.9)" << endl;
    doubleList.insert(2, 9.9);
    cout << doubleList;

    cout << "\nreplace(1, 8.8)" << endl;
    doubleList.replace(1, 8.8);
    cout << doubleList;

    cout << "\nremove(3)" << endl;
    doubleList.remove(3);
    cout << doubleList;

    cout << "\nSTRING DATATYPE" << endl;
    LinkedList<string> stringList;

    cout << "\nappend(\"CS20\"), append(\"Linked\"), append(\"List\")" << endl;
    stringList.append("CS20");
    stringList.append("Linked");
    stringList.append("List");
    cout << stringList;

    cout << "\ninsert(1, \"is\")" << endl;
    stringList.insert(1, "is");
    cout << stringList;

    cout << "\nreplace(0, \"Hello\")" << endl;
    stringList.replace(0, "Hello");
    cout << stringList;

    cout << "\ngetElement(2)" << endl;
    cout << "Result: " << stringList.getElement(2) << endl;

    cout << "\nEXCEPTION TEST: insert(10, \"oops\")" << endl;
    try {
        stringList.insert(10, "oops");
    } catch (string& s) {
        cout << s << endl;
    }

    cout << "\nremove(3)" << endl;
    stringList.remove(3);
    cout << stringList;

    return 0;
}
