#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int print_int_vector(vector<int> const &v) {
	for (auto it=v.begin(); it!=v.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	return 0;
}

int print_string_vector(vector<string> const &v) {
	for (auto it=v.begin(); it!=v.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	return 0;
}

int main() {
	vector<int> vi {32,3254,2345,2534312,3,3,41,34544431,534,52343,43423454,431};
	vi.push_back(12);
	vector<string> vs {"fdsf", "dfgre", "ferve", "qrevb", "reqreqvreq"};
	print_int_vector(vi);
	sort(vi.begin(), vi.end());
	print_int_vector(vi);

	print_string_vector(vs);
	sort(vs.begin(), vs.end());
	print_string_vector(vs);
	return 0;
}