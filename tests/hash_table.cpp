#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;

int main() {
	map<string, int> students {
		{"Alex", 0},
		{"Anna", 1},
		{"Roma", 2},
		{"Mikle", 3}
	};
	for (auto i: students) {
		cout << i.first << i.second << endl;
	}
}
