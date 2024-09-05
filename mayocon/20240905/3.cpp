// https://atcoder.jp/contests/abc225/tasks/abc225_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<pair<int,int>> V(N, {-1, -1});
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            V[x].second = y;
            V[y].first = x;
        } else if (t == 2) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            V[x].second = -1;
            V[y].first = -1;
        } else {
            int x;
            cin >> x;
            x--;
            while (V[x].first != -1) x = V[x].first;
            int y = x, cnt = 0;
            while (y != -1) {
                cnt++;
                y = V[y].second;
            }
            cout << cnt << " ";
            for (int k = 0; k < cnt; k++) {
                cout << x+1;
                if (k != cnt-1) {
                    cout << " ";
                    x = V[x].second;
                } else {
                    cout << "\n";
                }
            }
        }
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
