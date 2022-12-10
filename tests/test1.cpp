#include <iostream>
#include <string>

using namespace std;

enum class A {red, green, yellow};

int main() {
    A s {A::blue};
    switch(s) {
        case A::red:
            cout << "red\n";
            break;
        case A::green:
            cout << "green\n";
            break;
        default:
            cout << "color" << endl;
    }
    return 0;
}