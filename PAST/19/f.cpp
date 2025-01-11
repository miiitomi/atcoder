// https://atcoder.jp/contests/past19-open/tasks/past19_f
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
    string X, Y;
    cin >> X >> Y;
    vector<string> V{X, Y}, S(N), T(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> T[i];
        V.push_back(S[i]);
        V.push_back(T[i]);
    }
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    ll x = distance(V.begin(), lower_bound(V.begin(), V.end(), X));
    ll y = distance(V.begin(), lower_bound(V.begin(), V.end(), Y));
    ll M = V.size();
    vector<vector<ll>> G(M);
    for (int i = 0; i < N; i++) {
        string s = S[i], t = T[i];
        ll a = distance(V.begin(), lower_bound(V.begin(), V.end(), s));
        ll b = distance(V.begin(), lower_bound(V.begin(), V.end(), t));
        G[a].push_back(b);
    }

    vector<bool> reached(M, false);
    reached[x] = true;
    queue<int> Q;
    Q.push(x);

    while (!Q.empty()) {
        ll u = Q.front();
        Q.pop();
        for (ll v : G[u]) {
            if (reached[v]) continue;
            reached[v] = true;
            Q.push(v);
        }
    }

    if (reached[y]) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
