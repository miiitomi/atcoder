// https://atcoder.jp/contests/abc256/tasks/abc256_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N;
    cin >> N;
    vector<ll> cnt((int)2e+5 + 1, 0);
    for (int i = 0; i < N; i++) {
        ll l, r;
        cin >> l >> r;
        cnt[l]++;
        cnt[r]--;
    }
    for (int i = 0; i < (int)2e+5; i++) cnt[i+1] += cnt[i];

    bool is_in = false;
    for (int i = 1; i <= (int)2e+5; i++) {
        if (is_in) {
            if (cnt[i] == 0) {
                is_in = false;
                cout << i << "\n";
            }
        } else {
            if (cnt[i] > 0) {
                is_in = true;
                cout << i << " ";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
