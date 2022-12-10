#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <ctime>
#include <cmath>

using namespace std;

map<int, double> str_to_map(string const& s)
{
	map<int, double> m;

	string key, val, line, buf;
	line = s;
	istringstream iss(line);
	while (line.find(" ") != line.npos) {
		buf = line.substr(0, line.find(" "));
		key = buf.substr(0, buf.find(":"));
		val = buf.substr(buf.find(":") + 1, line.find(" "));
		m[stoi(key)] = stod(val);
		line.erase(0, line.find(" ") + 1);
	}
	key = line.substr(0, line.find(":"));
	val = line.substr(line.find(":") + 1, line.find(" "));
	m[stoi(key)] = stod(val);

	return m;
}

map<int, double> fill_element(int i, double value) {
	map<int, double> m;
	m[i] = value;
	return m;
}

int diagonal_fix(vector <map<int, double>>& A, vector <double>& b, int n) {
	int i, j, k, isnull = 0;
	for (i = 0; i < n; i++) {
		if (A[i].find(i) == A[i].end()) {
			isnull = 1;
			for (j = 0; j < n; j++)
				if (A[j].find(i) != A[j].end()) {
					isnull = 0;
					for (k = 0; k < n; k++) {
						if (A[j].find(k) != A[j].end() && A[i].find(k) != A[i].end())
							A[i][k] += A[j][k];
						else if (A[j].find(k) != A[j].end())
							A[i][k] = A[j][k];
					}
					b[i] += b[j];
					break;
				}
		}
	}
	return isnull;
}

void LU_decomposition(vector <map<int, double> > A, vector <map<int, double> >& L, vector <map<int, double> >& U, int n)
{
	int i, j, k;
	U = A;

	for (i = 0; i < n; i++)
		L.push_back(fill_element(i, 1));
	for (j = i; j < n; j++)
		if (U[j].find(i) != U[j].end() && \
			U[i].find(i) != U[i].end())
			L[j][i] = U[j][i] / U[i][i];

	for (k = 1; k < n; k++)
	{
		for (i = k - 1; i < n; i++)
			for (j = i; j < n; j++)
				if (U[j].find(i) != U[j].end() && \
					U[i].find(i) != U[i].end()) // Проверка что соответствующие элементы ненулевые
					L[j][i] = U[j][i] / U[i][i];

		for (i = k; i < n; i++)
			for (j = k - 1; j < n; j++)
				if (U[i].find(j) != U[i].end() && \
					U[k - 1].find(j) != U[k - 1].end() && \
					L[i].find(k - 1) != L[i].end()) // Check correspondent elements exist
					U[i][j] = U[i][j] - L[i][k - 1] * U[k - 1][j];
				else if (U[k - 1].find(j) != U[k - 1].end() && \
					L[i].find(k - 1) != L[i].end())
					U[i][j] = 0 - L[i][k - 1] * U[k - 1][j];
	}
}

void matrix_product(vector <map<int, double >> A, vector <map<int, double>>B, vector <map<int, double>>& C, int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		C.push_back(fill_element(i, 0));
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++) {
				if (A[i].find(k) != A[i].end() && \
					B[k].find(j) != B[k].end())
					C[i][j] += A[i][k] * B[k][j];
			}
	}
}

int read_matrix(vector <map<int, double >>& A, vector <double>& b, string filepath)
{
	ifstream file(filepath);
	int n, i;
	string str, buf;

	getline(file, str);
	n = stoi(str);
	cout << "Matrix size is: " << n << endl;
	for (i = 1; i <= n; i++) {
		getline(file, str);
		A.push_back(str_to_map(str));
	}
	getline(file, str);
	while (str.find(" ") != str.npos) {
		b.push_back(stod(str.substr(0, str.find(" "))));
		str.erase(0, str.find(" ") + 1);
	}
	b.push_back(stod(str));
	return n;
}

double random_double() {
	return double(rand()) / (double(RAND_MAX) + 1.0);
}

void generate_matrix(vector <map<int, double >>& A, vector <double>& b, int n)
{
	int i;
	cout << "Matrix size is: " << n << endl;
	for (i = 0; i < n; i++) {
		A.push_back(fill_element(i, random_double()));
		while (rand() % 10 > 8)
			A[i][rand() % n] = random_double();
		b.push_back(random_double());
	}
}

void write_matrix(vector <map<int, double>> A, int n, string table)
{
	int i, j;
	ofstream myfile;
	myfile.open("table" + table + ".txt");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (A[i].find(j) != A[i].end())
				myfile << A[i][j] << "\t";
			else
				myfile << 0 << "\t";
		}
		myfile << endl;
	}
	myfile.close();
}

void print_matrix(vector <map<int, double>> A, int n)
{
	int i, j, m;
	if (n < 7)
		m = n;
	else {
		m = 7;
		cout << "Only first 7 values of every line are printed." << endl;
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (A[i].find(j) != A[i].end())
				cout << A[i][j] << "\t";
			else
				cout << 0 << "\t";
		}
		cout << endl;
	}
}

void print_vector(vector<double> const& input)
{
	int i, m;
	if ((int)input.size() < 8)
		m = (int)input.size();
	else {
		m = 7;
	}
	for (i = 0; i < m; i++) {
		cout << input.at(i) << ' ';
	}
	cout << endl;
	if ((int)input.size() > 7)
		cout << "Only first 7 values are printed." << endl;
	cout << endl;
}

vector <double> solve_equation(vector <map<int, double>> L, vector <map<int, double>> U, vector <double> b, int n) {
	vector <double> x(n), y(n);
	int i, j;
	double sum;

	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j < i; j++)
			if (L[i].find(j) != L[i].end())
				sum += L[i][j] * y[j];
		y[i] = b[i] - sum;
	}
	for (i = n - 1; i >= 0; i--) {
		sum = 0;
		for (j = n - 1; j > i; j--)
			if (U[i].find(j) != U[i].end())
				sum += U[i][j] * x[j];
		x[i] = (y[i] - sum) / U[i][i];
	}
	return x;
}

double matrix_discrepancy(vector <map<int, double>> A, vector <map<int, double>> R, int n) {
	int i, j;
	double max_discr = 0, sum;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			sum = 0;
			if (R[i].find(j) != R[i].end() && A[i].find(j) != A[i].end()) {
				if (max_discr < abs(R[i][j] - A[i][j]))
					max_discr = abs(R[i][j] - A[i][j]);
				if (max_discr > 1) { cout << "check" << endl; }
			}
			else if (R[i].find(j) != R[i].end()) {
				if (max_discr < abs(R[i][j]))
					max_discr = abs(R[i][j]);
			}
			else if (A[i].find(j) != A[i].end()) {
				if (max_discr < abs(A[i][j]))
					max_discr = abs(A[i][j]);
			}
		}
	}
	return max_discr;
}

double discrepancy(vector <map<int, double>> A, vector <double> b, vector <double> x, int n) {
	int i, j;
	double max_discr = 0, sum;
	for (i = 0; i < n; i++) {
		sum = 0;
		for (j = 0; j < n; j++) {
			if (A[i].find(j) != A[i].end())
				sum += A[i][j] * x[j];
		}
		if (max_discr < abs(b[i] - sum))
			max_discr = abs(b[i] - sum);
	}
	return max_discr;
}