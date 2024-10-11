#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> P(N), Q(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) {
        cin >> Q[i];
        Q[i]--;
    }
    assert ((N <= 1000) && (M <= 1000));
    vector<bool> cnt(N, false);
    for (int i = 0; i < N; i++) {
        ll x = i;
        ll m = M;
        while (m > P[x]) {
            m -= P[x];
            x = Q[x];
        }
        cnt[x] = true;
    }
    
    for (int i = 0; i < N; i++) {
        if (cnt[i]) {
            cout << i+1 << " ";
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}