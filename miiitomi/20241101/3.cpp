// https://atcoder.jp/contests/abc097/tasks/arc097_a
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    string S;
    cin >> S;
    int N = S.size();
    vector<string> v;
    for (int i = 0; i < N; i++) {
        for (int k = 1; k <= 5; k++) {
            if (i+k > N) continue;
            v.push_back(S.substr(i, k));
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int K;
    cin >> K;
    cout << v[K-1] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
