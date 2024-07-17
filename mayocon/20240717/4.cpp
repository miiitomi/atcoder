// https://atcoder.jp/contests/abc293/tasks/abc293_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

bool f(int u, vector<ll> &to, vector<bool> &done) {
    if (to[u] == -1) return false;
    int v = to[u];
    done[v] = true;
    if (v % 2 == 1) v--;
    else v++;
    if (done[v]) return true;
    done[v] = true;
    return f(v, to, done);
}

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> to(2*N, -1);
    for (int i = 0; i < M; i++) {
        ll a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        a = 2*(a-1) + (b == 'B');
        c = 2*(c-1) + (d == 'B');
        to[a] = c;
        to[c] = a;
    }

    ll X = 0, Y = 0;
    vector<bool> done(2*N, false);
    for (int u = 0; u < 2*N; u += 2) {
        if (done[u]) continue;
        done[u] = true;
        bool res = f(u, to, done);
        if (res) X++;
        else {
            Y++;
            done[u+1] = true;
            f(u+1, to, done);
        }
    }

    cout << X << " " << Y << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
