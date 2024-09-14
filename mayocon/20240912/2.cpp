// https://atcoder.jp/contests/abc163/tasks/abc163_c
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
    vector<int> cnt(N, 0);
    for (int i = 1; i < N; i++) {
        int p;
        cin >> p;
        p--;
        cnt[p]++;
    }
    for (int i = 0; i < N; i++) cout << cnt[i] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
