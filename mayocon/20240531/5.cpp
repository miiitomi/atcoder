// https://atcoder.jp/contests/abc161/tasks/abc161_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<ll> f(ll N) {
    set<ll> S;
    for (ll x = 1; x*x <= N; x++) {
        if (N % x == 0) {
            S.insert(x);
            S.insert(N/x);
        }
    }
    S.erase(1);
    return S;
}

bool is_good(ll K, ll N) {
    while (N >= K) {
        if (N % K == 0) N /= K;
        else N %= K;
    }
    return N == 1;
}

void solve() {
    ll N;
    cin >> N;

    if (N == 2) {
        cout << 1 << endl;
        return;
    }

    set<ll> S = f(N-1);
    set<ll> T = f(N);
    for (ll t : T) {
        if (S.count(t)) continue;
        if (is_good(t, N)) S.insert(t);
    }

    cout << S.size() << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
