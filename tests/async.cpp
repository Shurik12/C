#include <iostream>
#include <vector>
#include <future>
#include <numeric>

using namespace std;

double accum(double* beg, double* end, double init) {
    return accumulate(beg, end, init);
}

double comp4(vector<double>& v) {
    auto v0 = &v[0];
    auto sz = v.size();
    if (sz < 10000) return accum(v0, v0+sz, 0.0);
    auto f0 = async(accum, v0, v0+sz/4, 0.0);
    auto f1 = async(accum, v0+sz/4, v0+sz/2, 0.0);
    auto f2 = async(accum, v0+sz/2, v0+sz*3/4, 0.0);
    auto f3 = async(accum, v0+sz*3/4, v0+sz, 0.0);
    // first quarter
    // second quarter
    // third quarter
    // four th quar ter
    return f0.get()+f1.get()+f2.get()+f3.get(); // collect and combine the results
}

int main() {
    double res;
    vector<double> v {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};
    res = comp4(v);
    cout << res << endl;
    return 0;
}