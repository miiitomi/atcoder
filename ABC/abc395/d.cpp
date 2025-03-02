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
    vector<int> p(N), q(N), r(N);
    iota(p.begin(), p.end(), 0);
    iota(q.begin(), q.end(), 0);
    iota(r.begin(), r.end(), 0);
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            p[a] = q[b];
        } else if (k == 2) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            swap(q[a], q[b]);
            swap(r[q[a]], r[q[b]]);
        } else {
            int a;
            cin >> a;
            a--;
            cout << r[p[a]]+1 << "\n";
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
