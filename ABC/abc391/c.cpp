#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N, Q, ans = 0;
    cin >> N >> Q;
    vector<int> pigeon(N), cnt(N, 1);
    iota(pigeon.begin(), pigeon.end(), 0);
    while (Q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int p, h;
            cin >> p >> h;
            p--; h--;
            int a = pigeon[p];
            cnt[a]--;
            if (cnt[a] == 1) ans--;
            cnt[h]++;
            if (cnt[h] == 2) ans++;
            pigeon[p] = h;
        } else {
            cout << ans << "\n";
        }
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
