// https://atcoder.jp/contests/abc297/tasks/abc297_e
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll cnt = 0;
    set<ll> S;
    S.insert(0);
    auto iter = S.begin();

    while (cnt < K) {
        ll a = *iter;
        for (ll b : A) S.insert(a + b);
        cnt++;
        iter++;
    }

    cout << *iter << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
