// https://atcoder.jp/contests/abc094/tasks/arc095_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;


void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i] *= 2;
    }
    sort(a.begin(), a.end());
    ll m = a[0];
    for (int i = 1; i <= N-1; i++) {
        if (abs(a.back()/2 - m) > abs(a.back()/2 - a[i])) {
            m = a[i];
        }
    }
    cout << a.back()/2 << " " << m/2 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
