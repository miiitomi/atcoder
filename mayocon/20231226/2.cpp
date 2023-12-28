// https://atcoder.jp/contests/abc195/tasks/abc195_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    int cnt = 0;
    for (ll x = 1; x <= N; x *= 1000) {
        ll y = min(1000 * x - 1, N);
        ans += (y - x + 1) * cnt;
        cnt++;
    }
    cout << ans << endl;
}
