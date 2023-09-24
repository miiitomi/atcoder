#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    double _x, _y, _r;
    cin >> _x >> _y >> _r;    
    ll X, Y, R;
    X = round(10000 * _x);
    Y = round(10000 * _y);
    R = round(10000 * _r);

    ll ans = 0;
    ll B = Y - R;
    if (B % 10000 != 0) {
        if (B < 0) B = B - (B % 10000);
        else B = B + (10000 - B%10000);
    }

    for (; B <= Y+R; B += 10000) {
        ll left = 0;
        ll right = 2*R;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if (mid*mid + (B - Y)*(B-Y) > R*R) {
                right = mid;
            } else {
                left = mid;
            }
        }
        ll R1 = X - left -1, R2 = X + left;
        if (R1 % 10000 != 0) {
            if (R1 > 0) R1 = R1 - (R1 % 10000);
            else R1 = R1 - (10000 + R1 % 10000);
        }
        if (R2 % 10000 != 0) {
            if (R2 > 0) R2 = R2 - (R2 % 10000);
            else R2 = R2 - (10000 + R2 % 10000);
        }
        ans += R2/10000 - R1 / 10000;
    }
    cout << ans << endl;
}
