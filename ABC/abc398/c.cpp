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
    map<int, vector<int>> mp;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        mp[-a].push_back(i);
    }
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        const auto &v = iter->second;
        if (v.size() > 1) continue;
        cout << v[0] << endl;
        return;
    }
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
