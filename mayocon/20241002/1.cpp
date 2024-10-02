// https://atcoder.jp/contests/abc213/tasks/abc213_b
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
    vector<pair<int,int>> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i].first;
        V[i].second = i+1;
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    cout << V[1].second << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
