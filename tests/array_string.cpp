#include <iostream>
#include <string>

using namespace std;

int processing_string(string s) {
	cout << s << endl;
	s += "\nAAAA";
	return 0;
}

int processing_string_1(string * s) {
	*s += "\nAAAA";
	return 0;
}

int main() {

	int i=0;
	string s = "Hello, World!", *s1 = new string;
	*s1 = "Hello, World!";
	cout << processing_string(*s1) << endl;
	cout << processing_string_1(s1) << endl;
	cout << *s1 << endl;
	delete s1;
	return 0;
}