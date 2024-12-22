// https://atcoder.jp/contests/abc257/tasks/abc257_c
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
    string S;
    cin >> S;
    vector<ll> A, C, W(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
        if (S[i] == '1') A.push_back(W[i]);
        else C.push_back(W[i]);
    }
    sort(A.begin(), A.end());
    sort(C.begin(), C.end());
    sort(W.begin(), W.end());
    W.push_back(0);
    W.push_back((ll)(2e+9));
    W.erase(unique(W.begin(), W.end()), W.end());
    ll ans = -INF;
    for (ll w : W) {
        ll tmp = 0;
        tmp += distance(lower_bound(A.begin(), A.end(), w), A.end());
        tmp += distance(C.begin(), lower_bound(C.begin(), C.end(), w));
        ans = max(ans, tmp);
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
