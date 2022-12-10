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

void test_case1(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x) {
	unsigned int start, end;
	int n;
	string filepath;
	// ----- Test Case 1 ----- //
	cout << "Test Case 1. Normal Matrix." << endl;
	filepath = "./test_case1.txt";
	n = read_matrix(A, b, filepath);
	if (diagonal_fix(A, b, n) == 1) {
		cout << "Matrix is singular." << endl;
		cout << endl;
	}
	else {
		start = clock();
		LU_decomposition(A, L, U, n);
		x = solve_equation(L, U, b, n);
		end = clock();
		cout << "Discrepancy is: " << discrepancy(A, b, x, n) << endl;
		cout << "Calculating time is: " << end - start << endl;
		cout << endl;
	}
	A.clear(); L.clear(); U.clear(); b.clear(); x.clear();
}

void test_case2(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x) {
	unsigned int start, end;
	int n;
	string filepath;
	// ----- Test Case 2 ----- //
	cout << "Test Case 2. Matrix with zero column." << endl;
	filepath = "./test_case2.txt";
	n = read_matrix(A, b, filepath);
	if (diagonal_fix(A, b, n) == 1) {
		cout << "Matrix is singular." << endl;
		cout << endl;
	}
	else {
		start = clock();
		LU_decomposition(A, L, U, n);
		x = solve_equation(L, U, b, n);
		end = clock();
		cout << "Discrepancy is: " << discrepancy(A, b, x, n) << endl;
		cout << "Calculating time is: " << end - start << endl;
		cout << endl;
	}
	A.clear(); L.clear(); U.clear(); b.clear(); x.clear();
}

void test_case3(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x) {
	unsigned int start, end;
	int n;
	string filepath;
	// ----- Test Case 3 ----- //
	cout << "Test Case 3. Matrix with zeros on diagonal." << endl;
	filepath = "./test_case3.txt";
	n = read_matrix(A, b, filepath);
	if (diagonal_fix(A, b, n) == 1) {
		cout << "Matrix is singular." << endl;
		cout << endl;
	}
	else {
		start = clock();
		LU_decomposition(A, L, U, n);
		x = solve_equation(L, U, b, n);
		end = clock();
		cout << "Discrepancy is: " << discrepancy(A, b, x, n) << endl;
		cout << "Calculating time is: " << end - start << endl;
		cout << endl;
	}
	A.clear(); L.clear(); U.clear(); b.clear(); x.clear();
}

void test_case4(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x) {
	unsigned int start, end;
	int n;
	// ----- Test Case 4 ----- //
	cout << "Test Case 4. Matrix with n = 100." << endl;
	n = 100;
	generate_matrix(A, b, n);
	cout << "Fisrt matrix: " << endl;
	print_matrix(A, n);
	start = clock();
	LU_decomposition(A, L, U, n);
	end = clock();
	cout << "Calculating LU matrix time: " << end - start << endl;
	start = clock();
	x = solve_equation(L, U, b, n);
	end = clock();
	cout << "Discrepancy is: " << discrepancy(A, b, x, n) << endl;
	cout << "Result vector: " << endl;
	print_vector(x);
	cout << "Solve equations time: " << end - start << endl;
	cout << endl;
	A.clear(); L.clear(); U.clear(); b.clear(); x.clear();
}

void test_case5(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x) {
	unsigned int start, end;
	int n;
	// ----- Test Case 5 ----- //
	cout << "Test Case 5. Matrix with n = 200." << endl;
	n = 200;
	generate_matrix(A, b, n);
	cout << "Fisrt matrix: " << endl;
	print_matrix(A, n);
	start = clock();
	LU_decomposition(A, L, U, n);
	end = clock();
	cout << "Calculating LU matrix time: " << end - start << endl;
	start = clock();
	x = solve_equation(L, U, b, n);
	end = clock();
	cout << "Discrepancy is: " << discrepancy(A, b, x, n) << endl;
	cout << "Result vector: " << endl;
	print_vector(x);
	cout << "Solve equations time: " << end - start << endl;
	cout << endl;
	A.clear(); L.clear(); U.clear(); b.clear(); x.clear();
}

void test_case6(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x) {
	unsigned int start, end;
	int n;
	// ----- Test Case 6 ----- //
	cout << "Test Case 6. Matrix with n = 400." << endl;
	n = 400;
	generate_matrix(A, b, n);
	cout << "Fisrt matrix: " << endl;
	print_matrix(A, n);
	start = clock();
	LU_decomposition(A, L, U, n);
	end = clock();
	cout << "Calculating LU matrix time: " << end - start << endl;
	start = clock();
	x = solve_equation(L, U, b, n);
	end = clock();
	cout << "Discrepancy is: " << discrepancy(A, b, x, n) << endl;
	cout << "Result vector: " << endl;
	print_vector(x);
	cout << "Solve equations time: " << end - start << endl;
	cout << endl;
	A.clear(); L.clear(); U.clear(); b.clear(); x.clear();
}

void test_case7(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x) {
	unsigned int start, end;
	int n;
	// ----- Test Case 7 ----- //
	cout << "Test Case 7. Matrix with n = 800." << endl;
	n = 1000;
	generate_matrix(A, b, n);
	cout << "Fisrt matrix: " << endl;
	print_matrix(A, n);
	start = clock();
	LU_decomposition(A, L, U, n);
	end = clock();
	cout << "Calculating LU matrix time: " << end - start << endl;
	start = clock();
	x = solve_equation(L, U, b, n);
	end = clock();
	cout << "Discrepancy is: " << discrepancy(A, b, x, n) << endl;
	cout << "Result vector: " << endl;
	print_vector(x);
	cout << "Solve equations time: " << end - start << endl;
	cout << endl;
	A.clear(); L.clear(); U.clear(); b.clear(); x.clear();
}

void test_case8(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x) {
	unsigned int start, end;
	int n, i;
	// ----- Test Case 8 ----- //
	cout << "Test Case 8. Matrix with n = 500. Solving equations 1000 times." << endl;
	n = 500;
	generate_matrix(A, b, n);
	cout << "Fisrt matrix: " << endl;
	print_matrix(A, n);
	start = clock();
	LU_decomposition(A, L, U, n);
	end = clock();
	cout << "Calculating LU matrix time: " << end - start << endl;
	start = clock();
	for (i = 0; i < 1000; i++)
		x = solve_equation(L, U, b, n);
	end = clock();
	cout << "Discrepancy is: " << discrepancy(A, b, x, n) << endl;
	cout << "Result vector: " << endl;
	print_vector(x);
	cout << "Solve equations 1000 times: " << end - start << endl;
	cout << endl;
	A.clear(); L.clear(); U.clear(); b.clear(); x.clear();
}

void run_tests(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x) {
	test_case1(A, L, U, b, x);
	test_case2(A, L, U, b, x);
	test_case3(A, L, U, b, x);
	test_case4(A, L, U, b, x);
	test_case5(A, L, U, b, x);
	test_case6(A, L, U, b, x);
	test_case7(A, L, U, b, x);
	test_case8(A, L, U, b, x);
}