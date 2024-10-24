// https://atcoder.jp/contests/abc315/tasks/abc315_b
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int M, sum = 0;
    cin >> M;
    vector<pair<int,int>> v;
    for (int i = 1; i <= M; i++) {
        int d;
        cin >> d;
        sum += d;
        for (int j = 1; j <= d; j++) v.push_back({i, j});
    }
    sum = (sum + 1) / 2 - 1;
    cout << v[sum].first << " " << v[sum].second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
