#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v {1,2,3,4,5,6,7,8,9};
	for (auto i=v.begin(); i!=v.end(); ++i) {
		cout << *i << endl;
	}
	for (int i=100; i<110; i++) {
		v.push_back(i);
	}
	cout << v.size() << endl;
	return 0;
}