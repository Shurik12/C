#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>
#include <cmath>
#include "headers.h"

using namespace std;

int main() {
	vector <map<int, double>> A, L, U; // It could be optimazed to store L and U matrices in A
	vector <double> b, x;
	unsigned int total_time_start = clock(), total_time_end;
	run_tests(A, L, U, b, x);
	total_time_end = clock();
	cout << "Total time: " << total_time_end - total_time_start << endl;
	return 0;
}
