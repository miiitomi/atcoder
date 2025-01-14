// https://atcoder.jp/contests/abc279/tasks/abc279_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, Q;
    cin >> N >> Q;
    vector<int> box(N+Q), ball(N+Q);
    iota(box.begin(), box.end(), 0);
    iota(ball.begin(), ball.end(), 0);
    dsu U(N+Q);
    int nxt = N;
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x, y;
            cin >> x >> y;
            x--; y--;
            swap(x, y);
            if (box[x] == -1) continue;
            int u = box[x], v = box[y];
            if (v == -1) {
                box[y] = u;
                ball[u] = y;
                box[x] = -1;
            } else {
                int r = U.merge(u, v);
                ball[u] = -1;
                ball[v] = -1;
                box[x] = -1;
                box[y] = r;
                ball[r] = y;
            }
        } else if (k == 2) {
            int x;
            cin >> x;
            x--;
            int u = box[x];
            if (u == -1) {
                box[x] = nxt;
                ball[nxt] = x;
            } else {
                int r = U.merge(u, nxt);
                ball[u] = -1;
                ball[nxt] = -1;
                box[x] = r;
                ball[r] = x;
            }
            nxt++;
        } else {
            int x;
            cin >> x;
            x--;
            x = U.leader(x);
            cout << ball[x]+1 << "\n";
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
