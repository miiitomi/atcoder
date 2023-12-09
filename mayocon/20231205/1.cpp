// https://atcoder.jp/contests/abc259/tasks/abc259_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, d;
    cin >> a >> b >> d;

    if (a == 0 && b == 0) {
        cout << fixed << setprecision(15) << 0.0 << " " << 0.0 << endl;
        return 0;
    }

    double r, theta;
    r = sqrt(a*a + b*b);
    a /= r;
    b /= r;
    theta = atan2(b, a);

    theta += (d / 360.0) * M_PI * 2;

    cout << fixed << setprecision(15) << r*cos(theta) << " " << r*sin(theta) << endl;
}
