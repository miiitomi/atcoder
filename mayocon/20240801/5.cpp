// https://atcoder.jp/contests/abc308/tasks/abc308_f
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
    ll sum = 0;
    multiset<ll> S;
    for (ll i = 0; i < N; i++) {
        ll p;
        cin >> p;
        sum += p;
        S.insert(p);
    }
    vector<pair<ll,ll>> V(M);
    for (int i = 0; i < M; i++) cin >> V[i].first;
    for (int i = 0; i < M; i++) cin >> V[i].second;
    sort(V.begin(), V.end(), [](const pair<ll, ll> &p, const pair<ll, ll> &q) {
        if (p.second != q.second) return p.second > q.second;
        return p.first < q.first;
    });

    for (pair<ll, ll> &p : V) {
        auto iter = S.lower_bound(p.first);
        if (iter == S.end()) continue;
        sum -= p.second;
        S.erase(iter);
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
