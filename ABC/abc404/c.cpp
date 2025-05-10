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
    if (M != N) {
        cout << "No\n";
        return;
    }
    vector<int> cnt(N, 0);
    dsu U(N);
    for (int m = 0; m < M; m++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cnt[a]++;
        cnt[b]++;
        U.merge(a, b);
    }

    if (cnt != vector<int>(N, 2) || U.size(0) != N) cout << "No\n";
    else cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
