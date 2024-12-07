// https://atcoder.jp/contests/abc278/tasks/abc278_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N;
vector<string> S;
map<pair<ll,ll>, bool> mp;

bool rec(ll st, ll last) {
    if (mp.contains(make_pair(st, last))) return mp[make_pair(st, last)];
    for (int i = 0; i < N; i++) {
        if (st & (1 << i) || (last != -1 && S[last].back() != S[i].front())) continue;
        bool res = rec(st ^ (1 << i), i);
        if (!res) return mp[make_pair(st, last)] = true;
    }
    return mp[make_pair(st, last)] = false;
}

void solve() {
    cin >> N;
    S.resize(N);
    for (string &s: S) cin >> s;
    if (rec(0, -1)) cout << "First\n";
    else cout << "Second\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
