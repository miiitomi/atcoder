// https://atcoder.jp/contests/abc142/tasks/abc142_c
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
        int a;
        cin >> a;
        V[i] = {a, i};
    }
    sort(V.begin(), V.end());
    for (auto p : V) {
        cout << p.second+1 << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
