#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<bool> is_condained(N+1, false);
    while (M--) {
        int a;
        cin >> a;
        is_condained[a] = true;
    }
    vector<int> ans;
    for (int x = 1; x <= N; x++) {
        if (is_condained[x]) continue;
        ans.push_back(x);
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
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
