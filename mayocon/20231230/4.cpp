// https://atcoder.jp/contests/abc230/tasks/abc230_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    ll left = 1, ans = 0;
    while (left <= N) {
        ll x = N / left;
        ll l = left, r = N+1;
        while (r-l > 1) {
            ll m = (r+l)/2;
            if (N/m >= x) l = m;
            else r = m;
        }
        ans += x * (l - left + 1);
        left = l+1;
    }
    cout << ans << endl;
}
