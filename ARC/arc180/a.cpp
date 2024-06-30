// https://atcoder.jp/contests/arc180/tasks/arc180_a
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = (ll)1e+9 + 7;

void solve() {
    ll N;
    string S;
    cin >> N >> S;

    ll ans = 1;
    string tmp;
    for (int i = 0; i < N; i++) {
        if (tmp.empty() || tmp.back() != S[i]) {
            tmp.push_back(S[i]);
        } else {
            ans *= ((ll)tmp.size()+1)/2;
            ans %= MOD;
            tmp = "";
            tmp.push_back(S[i]);
        }
    }
    ans *= ((ll)tmp.size()+1)/2;
    ans %= MOD;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
