/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 12, 2018, 8:14 PM
 */

#include <iostream>
#include <vector>
#include <chrono>
#include <ratio>
#include <algorithm>
#include <iterator>


using namespace std;
using namespace std::chrono;

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

typedef int (*function) (int, int); // function pointer type definition

function fun(int type) {
    if (type == 0)
        return add;

    if (type == 1)
        return sub;
}

struct Data {
public:
    char name[20];
    mutable int age; // constant olarak deklere edilmiş bir struct elemanını değiştirebilmek için
};

class Base final { // prevent deriving class from this class !!!!!!!!!!!
public:

    Base() {
        std::cout << "Constructor of Base\n";
    }

    Base(const Base&) {
        std::cout << "Copt Constructor of Base\n";
    }
};

struct Double {
    int m_val = 2;

    Double(int val) : m_val(val) {
    }

    int operator()(int elem) {
        return m_val *elem;
    }


};

int main(int argc, char** argv) {

    int* z = static_cast<int*> (malloc(sizeof (int))); // in C language.......
    *z = 10000;

    const int num = 10;
    int* ptr = (int*) &num; // even we type_cast num to non-constant value does not change
    *ptr = 100;
    std::cout << num << '\n'; // result is again 10;

    const Data d = {"Nebi", 35};
    d.age = 24;

    int i = 10;

    int &r = i;

    r = 6;

    int &r1 = r;

    int&r2 = r1;

    cout << r2 << i << r1 << '\n';

    ///////////vector size() and capacity() ///////////////////////////
    // if size passess capacity, capacity becomes double times of previous capacity!!!!!!!!
    vector<int> vec;
    std::cout << "vec size() : " << vec.size() << '\n';
    std::cout << "vec capacity() : " << vec.capacity() << '\n';
    vec.push_back(1);
    std::cout << "vec size() : " << vec.size() << '\n';
    std::cout << "vec capacity() : " << vec.capacity() << '\n';
    std::cout << "vec size() : " << vec.size() << '\n';
    std::cout << "vec capacity() : " << vec.capacity() << '\n';
    vec.push_back(1);
    std::cout << "vec size() : " << vec.size() << '\n';
    std::cout << "vec capacity() : " << vec.capacity() << '\n';
    vec.push_back(1);
    std::cout << "vec size() : " << vec.size() << '\n';
    std::cout << "vec capacity() : " << vec.capacity() << '\n';
    vec.push_back(1);
    std::cout << "vec size() : " << vec.size() << '\n';
    std::cout << "vec capacity() : " << vec.capacity() << '\n';
    vec.push_back(1);
    std::cout << "vec size() : " << vec.size() << '\n';
    std::cout << "vec capacity() : " << vec.capacity() << '\n';
    vec.push_back(1);
    std::cout << "vec size() : " << vec.size() << '\n';
    std::cout << "vec capacity() : " << vec.capacity() << '\n';
    vec.push_back(1);

    ///

    int (*p)(int, int) = add;



    std::cout << p(3, 4) << '\n';


    /////////// returning a function pointer and excuting it
    function f = fun(0);
    std::cout << f(2, 4) << '\n';
    //////////////////////////////////////////////////////////////

    ///////////////arrays of functions ///////////////////////////////
    function funcArray[] = {add, sub};

    int res1 = funcArray[0](3, 4);
    int res2 = funcArray[1](5, 2);

    std::cout << "res1 : " << res1 << "\nres2 : " << res2 << '\n';

    int arg1;

    char* arg2;

    std::cout << printf("hello world\n") << '\n';

    //  std::cout << scanf("%d %s", &arg1, &arg2);


    int numr = 3; //0011

    int shiftPos = 2; //0100

    numr |= (1 << shiftPos); //0100 or 0011 = 0111

    std::cout << "numr : " << numr << '\n';

    numr &= ~(1 << shiftPos); // 0111 & 1011

    std::cout << "numr : " << numr << '\n';



    vector<int> vect{1, 2, 3, 4, 5, 6, 7};

    int x = 2;

    for_each(vect.begin(), vect.end(), Double(x));

    vector<int>::iterator iter = vect.begin();

    for (; iter != vect.end(); iter++)
        std::cout << *iter << '\n';

    istreambuf_iterator<char> ci(cin);
    ostreambuf_iterator<char> ou(cout);
    while (*ci != 'x') {
        *ou = *ci;
        ++ou;
        ++ci;
    }

    return 0;
}

