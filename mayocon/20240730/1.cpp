// https://atcoder.jp/contests/abc241/tasks/abc241_b
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
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    while (M--) {
        ll b;
        cin >> b;
        auto iter = find(A.begin(), A.end(), b);
        if (iter == A.end()) {
            cout << "No\n";
            return;
        }
        A.erase(iter);
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
