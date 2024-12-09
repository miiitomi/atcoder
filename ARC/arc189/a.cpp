#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

vector<mint> F(1e+6, 1);
vector<mint> P(1e+6, 1);

mint C(int n, int r) {
    return P[n]/(P[n-r]*P[r]);
}

void solve() {
    ll N;
    cin >> N;
    vector<pair<int,ll>> V;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (V.empty() || V.back().first != a) V.push_back({a, 1});
        else V.back().second++;
    }
    int l = 1;
    mint ans = 1;
    ll cnt = 0;
    for (auto v : V) {
        if (v.first != l || v.second%2 == 0) {
            cout << 0 << endl;
            return;
        }
        if (v.second >= 3) ans *= C(cnt+(v.second-1)/2, (v.second-1)/2) * F[v.second-2];
        l = (l + v.second) % 2;
        cnt += (v.second-1)/2;
    }
    cout << ans.val() << endl;
}

int main() {
    for (int x = 3; x < 1e+6; x += 2) F[x] = F[x-2] * x;
    for (int x = 1; x < 1e+6; x++) P[x] = x * P[x-1];
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
