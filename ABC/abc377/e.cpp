#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;

template<typename T> T mod_pow(T a, ll n, ll mod) {
    if (n == 0) return 1;
    T res = mod_pow(a, n/2, mod);
    if (n % 2 == 1) return res * res % mod * a % mod;
    return res * res % mod;
}

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }
    vector<ll> Q(N, -1);
    for (int i = 0; i < N; i++) {
        if (Q[i] != -1) continue;
        deque<ll> v, w;
        v.push_back(i);
        w.push_back(P[i]);
        while (w.back() != i) {
            v.push_back(w.back());
            w.push_back(P[v.back()]); 
        }
        ll m = w.size();
        ll p = (mod_pow(2LL, K, m) + m - 1) % m;
        while (p--) {
            w.push_back(w.front());
            w.pop_front();
        }
        for (int i = 0; i < m; i++) {
            Q[v[i]] = w[i];
        }
    }

    for (int i = 0; i < N; i++) {
        cout << Q[i]+1;
        if (i == N-1) cout << "\n";
        else cout << " ";
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
