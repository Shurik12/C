#include <iostream>
#include <unique_ptr>

using namespace std;

int main() {
    int *p = new int;
    unique_ptr<int> sp {new int};
    int i = 100;
    if (i>94) {
        return 1;
    } else {
        continue;
    }
    delete p;
    return 0;
}