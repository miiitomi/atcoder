#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    string S;
    cin >> N >> S;
    fenwick_tree<int> ft(N);
    int mi = 1e+9, ma = -1;
    for (int i = 0; i < N; i++) {
        if (S[i] != '1') continue;
        mi = min(mi, i);
        ma = max(ma, i);
        ft.add(i, 1);
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '1' || !(mi < i && i < ma)) continue;
        ans += min(ft.sum(mi, i+1), ft.sum(i, ma+1));
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
