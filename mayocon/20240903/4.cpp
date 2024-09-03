// https://atcoder.jp/contests/abc235/tasks/abc235_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll a, N;
    cin >> a >> N;
    ll M = (ll)1e+7;
    vector<ll> d(M, INF);
    d[1] = 0;
    queue<ll> Q;
    Q.push(1);
    while (!Q.empty()) {
        ll n = Q.front();
        Q.pop();

        if (n == N) {
            cout << d[n] << endl;
            return;
        }

        if (n*a < M) {
            ll x = n*a;
            if (d[x] > d[n]+1) {
                d[x] = d[n]+1;
                Q.push(x);
            }
        }

        if (n >= 10 && n%10 != 0) {
            string s = to_string(n);
            s = s.back() + s.substr(0, s.size()-1);
            ll x = stoll(s);
            if (d[x] > d[n]+1) {
                d[x] = d[n]+1;
                Q.push(x);
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
