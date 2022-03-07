#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(ll K, ll R, ll B, ll x, ll y) {
    if (K > R || K > B) return false;
    return (R-K)/(x-1) + (B-K)/(y-1) >= K;
}

int main() {
    ll R, B, x, y;
    cin >> R >> B >> x >> y;

    ll left = 0;
    ll right = (ll)1e18 + 1;

    while (right - left > 1) {
        ll mid = (left + right) / 2;
        if (f(mid, R, B, x, y)) left = mid;
        else right = mid;
    }

    cout << left << endl;
}
