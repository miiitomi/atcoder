// https://atcoder.jp/contests/abc257/tasks/abc257_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<ll> x, y, P;
ll dist(ll i, ll j) {return abs(x[i]-x[j])+abs(y[i]-y[j]);}

bool can(ll S) {
    vector<vector<ll>> G(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (S*P[i] >= dist(i, j)) G[i].push_back(j);
        }
    }
    for (int s = 0; s < N; s++) {
        vector<ll> d(N, INF);
        d[s] = 0;
        queue<ll> Q;
        Q.push(s);
        while (!Q.empty()) {
            ll t = Q.front();
            Q.pop();
            for (ll u : G[t]) {
                if (d[u] < INF) continue;
                d[u] = d[t] + 1;
                Q.push(u);
            }
        }
        if (*max_element(d.begin(), d.end()) < INF) return true;
    }
    return false;
}

void solve() {
    cin >> N;
    x.resize(N); y.resize(N); P.resize(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i] >> P[i];
    ll left = 0, right = 4e+9;
    while (right - left > 1) {
        ll m = (left + right)/2;
        if (can(m)) right = m;
        else left = m;
    }
    cout << right << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
