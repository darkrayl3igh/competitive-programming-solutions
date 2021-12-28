#include "../bits/stdc++.h"

using namespace std;

class A {
public:
    A() {
        cout << " A Constructed " << endl;
    }
    ~A() {
        cout << " A Destructed " << endl;
    }
};

class B : public A{
public:
    B() {
        cout << " B Constructed " << endl;
    }
    ~B() {
        cout << " B Destructed " << endl;
    }
};

int main() {

    A a;
    //A* a = new A();
    cout << endl;

    B b;
    //B* b = new B();

    cout << endl;

    return 0;
}