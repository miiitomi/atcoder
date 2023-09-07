// https://atcoder.jp/contests/abc144/tasks/abc144_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    ll ans = 1e+15;

    for (ll x = 1; x*x <= N; x++) {
        ll y = N/x;
        if (x * y == N) {
            ans = min(ans, (x-1)+(y-1));
        }
    }

    cout << ans << endl;
}
