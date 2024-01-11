// https://atcoder.jp/contests/abc162/tasks/abc162_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll ans = 0, N;
    cin >> N;
    for (ll x = 1; x <= N; x++) {
        if (x % 3 == 0 || x % 5 == 0) continue;
        ans += x;
    }
    cout << ans << endl;
}
