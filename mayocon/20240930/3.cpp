// https://atcoder.jp/contests/abc150/tasks/abc150_c
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
    vector<ll> v(N);
    iota(v.begin(), v.end(), 1);
    ll a = 0, b = 0;
    vector<ll> P(N), Q(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> Q[i];
    ll cnt = 1;
    do {
        if (v == P) a = cnt;
        if (v == Q) b = cnt;
        cnt++;
    } while (next_permutation(v.begin(), v.end()));

    cout << abs(a-b) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
