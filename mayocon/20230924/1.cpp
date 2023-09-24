// https://atcoder.jp/contests/abc180/tasks/abc180_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<double> X(N);
    for (int i = 0; i < N; i++) {
        double x;
        cin >> x;
        X[i] = abs(x);
    }

    double m = 0, e = 0, c = 0;
    for (double x : X) {
        m += x;
        e += x*x;
        c = max(c, x);
    }
    cout << fixed << setprecision(15);
    cout << m << endl;
    cout << sqrt(e) << endl;
    cout << c << endl;
}
