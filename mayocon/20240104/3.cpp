// https://atcoder.jp/contests/abc279/tasks/abc279_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B;

double f(double x) {
    return B*(x-1) + A / sqrt(x);
}

int main() {
    cin >> A >> B;
    double left = 1.0, right = 2e+18;
    while (right - left >= 1) {
        double a = left + (right - left) / 3, b = left + 2 * (right - left) / 3;
        if (f(a) < f(b)) right = b;
        else left = a;
    }

    ll x = round(left);
    double ans = 2e+18;
    for (ll y = max(1LL, x-5); y <= x+5; y++) {
        double tmp = f((double)y);
        ans = min(ans, tmp);
    }

    cout << fixed << setprecision(15) << ans << endl;
}
