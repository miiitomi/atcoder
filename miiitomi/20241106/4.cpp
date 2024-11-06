// https://atcoder.jp/contests/abc098/tasks/arc098_b
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
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<deque<ll>> B(20);
    for (int i = 0; i < N; i++) {
        ll a = A[i];
        for (int k = 0; k < 20; k++) {
            if (!(a & (1 << k))) continue;
            B[k].push_back(i);
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll r = N-1;
        for (int k = 0; k < 20; k++) {
            if ((int)B[k].size() <= 1) continue;
            r = min(r, B[k][1]-1);
        }
        ans += r - i + 1;
        for (int k = 0; k < 20; k++) {
            if (!B[k].empty() && B[k].front() == i) B[k].pop_front();
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
