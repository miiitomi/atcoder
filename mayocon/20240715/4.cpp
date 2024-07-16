// https://atcoder.jp/contests/abc304/tasks/abc304_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll W, H, N, A, B;
    cin >> W >> H >> N;
    vector<ll> p(N), q(N);
    for (int i = 0; i < N; i++) cin >> p[i] >> q[i];
    cin >> A;
    vector<ll> a(A+1, 0);
    for (int i = 1; i <= A; i++) cin >> a[i];
    a.push_back(INF);
    cin >> B;
    vector<ll> b(B+1, 0);
    for (int i = 1; i <= B; i++) cin >> b[i];
    b.push_back(INF);

    map<pair<ll,ll>, ll> mp;
    for (int i = 0; i < N; i++) {
        ll x = distance(a.begin(), lower_bound(a.begin(), a.end(), p[i]));
        ll y = distance(b.begin(), lower_bound(b.begin(), b.end(), q[i]));
        mp[make_pair(x, y)] += 1;
    }
    ll ma = -INF, mi = INF*(ll)((ll)mp.size() == (A+1)*(B+1));
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        ll v = iter->second;
        ma = max(ma, v);
        mi = min(mi, v);
    }

    cout << mi << " " << ma << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
