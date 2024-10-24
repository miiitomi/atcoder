// https://atcoder.jp/contests/abc289/tasks/abc289_g
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> B(N);
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(B.begin(), B.end(), [](const ll &l, const ll &r){return l > r;});
    vector<tuple<ll,ll,ll>> cht;
    cht.push_back({0, B[0], 1});
    for (ll i = 1; i < N; i++) {
        ll na = (i+1)*B[i], nb = i+1, x = 0;
        while (!cht.empty()) {
            auto [l, a, b] = cht.back();
            x = 0;
            if (a-na > 0) x = (a - na + nb - b - 1)/(nb - b);
            if (x <= l) cht.pop_back();
            else break;
        }
        cht.push_back({x, na, nb});
    }

    for (int _ = 0; _ < M; _++) {
        ll c;
        cin >> c;
        auto iter = lower_bound(cht.begin(), cht.end(), make_tuple(c+1, 0LL, 0LL));
        iter--;
        auto [l, a, b] = *iter;
        cout << a + b*c << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
