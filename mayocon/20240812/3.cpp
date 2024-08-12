// https://atcoder.jp/contests/abc265/tasks/abc265_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, P, Q, R;
    cin >> N >> P >> Q >> R;
    vector<ll> A(N), S(N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S[i+1] = S[i] + A[i];
    }

    for (int i = 0; i < N; i++) {
        auto iter1 = lower_bound(S.begin(), S.end(), S[i]+P);
        if (iter1 == S.end() || *iter1 != S[i]+P) continue;
        auto iter2 = lower_bound(iter1, S.end(), *iter1+Q);
        if (iter2 == S.end() || *iter2 != *iter1+Q) continue;
        auto iter3 = lower_bound(iter2, S.end(), *iter2+R);
        if (iter3 == S.end() || *iter3 != *iter2+R) continue;
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
