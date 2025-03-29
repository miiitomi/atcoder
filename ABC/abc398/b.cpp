#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<int> cnt(14, 0);
    for (int i = 0; i < 7; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    for (int i = 1; i <= 13; i++) {
        for (int j = 1; j <= 13; j++) {
            if (i == j) continue;
            if (cnt[i] >= 3 && cnt[j] >= 2) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
