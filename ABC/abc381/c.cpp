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
    string S;
    cin >> N >> S;
    int ans = 1;
    vector<pair<char,int>> V;
    for (char c : S) {
        if (V.empty() || V.back().first != c) V.push_back({c, 1});
        else V.back().second++;
    }
    for (int i = 1; i < (int)V.size()-1; i++) {
        auto p = V[i-1], q = V[i], r = V[i+1];
        if (p.first == '1' && q == make_pair('/', 1) && r.first == '2') {
            ans = max(ans, 1 + 2*min(p.second, r.second));
        }
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
