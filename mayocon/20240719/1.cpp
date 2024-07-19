// https://atcoder.jp/contests/abc173/tasks/abc173_b
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
    vector<int> C(4, 0);
    vector<string> V = {"AC", "WA", "TLE", "RE"};

    while (N--) {
        string s;
        cin >> s;
        int i = distance(V.begin(), find(V.begin(), V.end(), s));
        C[i]++;
    }

    for (int k = 0; k < 4; k++) {
        cout << V[k] << " x " << C[k] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
