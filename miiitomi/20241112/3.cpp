// https://atcoder.jp/contests/abc179/tasks/abc179_e
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, X, M;
    cin >> N >> X >> M;
    vector<bool> reached(M, false);
    reached[X] = true;
    vector<ll> A{X};
    ll Y;
    while (true) {
        ll x = A.back();
        ll y = (x * x) % M;
        if (reached[y]) {
            Y = y;
            break;
        }
        reached[y] = true;
        A.push_back(y);
    }
    ll ans = 0;
    ll i = 0;
    while (A[i] != Y) {
        ans += A[i];
        i++;
        N--;
    }
    ll K = A.size()-i;
    ll sum = 0;
    for (int j = i; j < (int)A.size(); j++) sum += A[j];
    ans += (N/K)*sum;
    N %= K;
    while (N > 0) {
        ans += A[i];
        i++;
        N--;
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
