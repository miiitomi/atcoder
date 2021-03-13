#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    double a = 0.0;
    for (int i = 1; i < N; i++) {
        a += (1.0 / (double)i);
    }
    double ans = a * (double)N;
    cout << fixed << setprecision(10) << ans << endl;
}