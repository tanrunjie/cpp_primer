#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    ostream_iterator<int, char> out(cout, " ");

    list<int> one(5, 2);

    int stuff[5] = {1, 2, 4, 8, 6};
    list<int> two;
    two.insert(two.begin(), stuff, stuff + 5);
    int more[6] = {6, 4, 2, 4, 6, 5};
    list<int> three(two);
    three.insert(three.end(), more, more + 6);

    cout << "List one: ";
    copy(one.begin(), one.end(), out);
    cout << endl;

    cout << "List two: ";
    copy(two.begin(), two.end(), out);
    cout << endl;
    cout << "List three: ";
    copy(three.begin(), three.end(), out);
    cout << endl;

    three.remove(2);
    cout <<"List three minue 2s:";
    copy(three.begin(), three.end(), out);
    cout << endl;
    three.splice(three.begin(), one);
    cout << "List three after splice:";
    copy(three.begin(), three.end(), out);
    cout << endl << "List one: ";
    copy(one.begin(), one.end(), out);
    cout << endl;

    three.unique();
    cout << "List three after unique:";
    copy(three.begin(), three.end(), out);
    three.sort();
    three.unique();
    cout << endl << "List three after sort & unique:";
    copy(three.begin(), three.end(), out);
    cout << endl;

    two.sort();
    three.merge(two);
    cout <<"List three merge sorted list two:" << endl;
    copy(three.begin(), three.end(), out);



    return 0;
}