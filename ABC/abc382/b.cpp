#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, D;
    string S;
    cin >> N >> D >> S;
    vector<int> a;
    for (int i = 0; i < N; i++) if (S[i] == '@') a.push_back(i);
    reverse(a.begin(), a.end());
    for (int i = 0; i < D; i++) {
        int j = a[i];
        S[j] = '.';
    }
    cout << S << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
