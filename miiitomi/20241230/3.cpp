// https://atcoder.jp/contests/abc134/tasks/abc134_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N+1, 0), B(N+1, 0);
    int cnt = 0;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = N; i >= 1; i--) {
        int sum = 0;
        for (int x = 2*i; x <= N; x += i) sum ^= B[x];
        if (sum != A[i]) {
            B[i] = 1;
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (int i = 1; i <= N; i++) {
        if (B[i]) cout << i << " ";
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
