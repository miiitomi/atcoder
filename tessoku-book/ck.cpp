#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x + (x * x * x);
}

int main() {
    double N;
    cin >> N;

    double left = 0;
    double right = 100.0;

    while (right - left > 0.0001) {
        double mid = (left + right) / 2.0;
        if (f(mid) > N) {
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << right << endl;
}
