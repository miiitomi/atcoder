// https://atcoder.jp/contests/abc319/tasks/abc319_d
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
    vector<ll> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];
    ll l = *max_element(L.begin(), L.end())-1;
    ll r = INF;
    while (r-l > 1) {
        ll m = (l + r)/2;
        ll cnt = 0, tmp = 0;
        for (int i = 0; i < N; i++) {
            if (tmp + L[i]+1 <= m) tmp += L[i]+1;
            else if (tmp+L[i] <= m) {
                cnt++;
                tmp = 0;
            } else {
                cnt++;
                tmp = L[i]+1;
            }
        }
        if (tmp > 0) cnt++;
        if (cnt <= M) r = m;
        else l = m;
    }
    cout << r << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
