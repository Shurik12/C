#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	set<int> s {1,2,3,4,5,6,7};
	s.insert(6);
	for ( auto i: s) {
		// cout << i << "\n";
		cout << s.count(6) << endl;
	}
	return 0;
}
