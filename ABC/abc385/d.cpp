#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M, x, y;
    cin >> N >> M >> x >> y;
    map<ll, set<ll>> R, C;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        R[x].insert(y);
        C[y].insert(x);
    }
    ll cnt = 0;
    while (M--) {
        char d;
        ll c;
        cin >> d >> c;
        if (d == 'U') {
            auto iter = R[x].lower_bound(y);
            while (iter != R[x].end() && *iter <= y+c) {
                ll a = *iter;
                C[a].erase(x);
                iter = R[x].erase(iter);
                cnt++;
            }
            y += c;
        } else if (d == 'D') {
            auto iter = R[x].lower_bound(y);
            while (iter != R[x].begin()) {
                iter--;
                ll a = *iter;
                if (a < y-c) break;
                C[a].erase(x);
                iter = R[x].erase(iter);
                cnt++;
            }
            y -= c;
        } else if (d == 'L') {
            auto iter = C[y].lower_bound(x);
            while (iter != C[y].begin()) {
                iter--;
                ll a = *iter;
                if (a < x-c) break;
                R[a].erase(y);
                iter = C[y].erase(iter);
                cnt++;
            }
            x -= c;
        } else {
            auto iter = C[y].lower_bound(x);
            while (iter != C[y].end() && *iter <= x+c) {
                ll a = *iter;
                R[a].erase(y);
                iter = C[y].erase(iter);
                cnt++;
            }
            x += c;
        }
    }
    cout << x << " " << y << " " << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
