#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W, Q;
    cin >> H >> W >> Q;
    vector<set<ll>> R(H), C(W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            R[i].insert(j);
            C[j].insert(i);
        }
    }
    ll cnt = H*W;
    while (Q--) {
        ll r, c;
        cin >> r >> c;
        r--; c--;
        if (R[r].contains(c)) {
            R[r].erase(c);
            C[c].erase(r);
            cnt--;
            continue;
        }
        auto iter = R[r].lower_bound(c);
        if (iter != R[r].end()) {
            ll x = *iter;
            R[r].erase(x);
            C[x].erase(r);
            cnt--;
        }
        iter = R[r].lower_bound(c);
        if (iter != R[r].begin()) {
            iter--;
            ll x = *iter;
            R[r].erase(x);
            C[x].erase(r);
            cnt--;
        }
        auto iter2 = C[c].lower_bound(r);
        if (iter2 != C[c].end()) {
            ll x = *iter2;
            C[c].erase(x);
            R[x].erase(c);
            cnt--;
        }
        iter2 = C[c].lower_bound(r);
        if (iter2 != C[c].begin()) {
            iter2--;
            ll x = *iter2;
            C[c].erase(x);
            R[x].erase(c);
            cnt--;
        }
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
