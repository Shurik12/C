#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>
#include <cmath>
using namespace std;
int main();

map<int, double> str_to_map(string const& s);
map<int, double> fill_element(int i, double value);
int diagonal_fix(vector <map<int, double>>& A, vector <double>& b, int n);
void LU_decomposition(vector <map<int, double> > A, vector <map<int, double> >& L, vector <map<int, double> >& U, int n);
void matrix_product(vector <map<int, double >> A, vector <map<int, double>>B, vector <map<int, double>>& C, int n);
int read_matrix(vector <map<int, double >>& A, vector <double>& b, string filepath);
double random_double();
void generate_matrix(vector <map<int, double >>& A, vector <double>& b, int n);
void write_matrix(vector <map<int, double>> A, int n, string table);
void print_matrix(vector <map<int, double>> A, int n);
void print_vector(vector<double> const& input);
vector <double> solve_equation(vector <map<int, double>> L, vector <map<int, double>> U, vector <double> b, int n);
double matrix_discrepancy(vector <map<int, double>> A, vector <map<int, double>> R, int n);
double discrepancy(vector <map<int, double>> A, vector <double> b, vector <double> x, int n);

void test_case1(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x);
void test_case2(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x);
void test_case3(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x);
void test_case4(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x);
void test_case5(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x);
void test_case6(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x);
void test_case7(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x);
void test_case8(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x);
void run_tests(vector <map<int, double>> A, vector <map<int, double>>& L, vector <map<int, double>>& U,
	vector <double> b, vector <double>& x);
