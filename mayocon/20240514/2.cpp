// https://atcoder.jp/contests/abc269/tasks/abc269_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> V;
    for (ll x = N; x >= 0; x = (x-1)&N) {
        V.push_back(x);
        if (x == 0) break;
    }
    reverse(V.begin(), V.end());
    for (ll a : V) cout << a << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
