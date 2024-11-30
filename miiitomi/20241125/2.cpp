// https://atcoder.jp/contests/abc314/tasks/abc314_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, Q;
    string S;
    cin >> N  >> S >> Q;
    vector<ll> v(N, -1);
    ll d = -1;
    bool small = true;
    for (int q = 0; q < Q; q++) {
        ll t, x;
        char c;
        cin >> t >> x >> c;
        if (t == 1) {
            x--;
            v[x] = q;
            S[x] = c;
        } else if (t == 2) {
            d = q;
            small = true;
        } else {
            d = q;
            small = false;
        }
    }
    for (int i = 0; i < N; i++) {
        if (d <= v[i]) cout << S[i];
        else if ((small && ('a' <= S[i] && S[i] <= 'z')) || (!small && 'A' <= S[i] && S[i] <= 'Z')) cout << S[i];
        else if ('a' <= S[i] && S[i] <= 'z') cout << (char)('A' + S[i] - 'a');
        else cout << (char)('a' + S[i] - 'A');
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
