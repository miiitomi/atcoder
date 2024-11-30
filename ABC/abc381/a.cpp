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
    if (N % 2 == 0) {
        cout << "No\n";
        return;
    }

    bool ok = true;
    for (int i = 1; i <= N; i++) {
        if (i <= (N+1)/2-1) {
            if (S[i-1] != '1') ok = false;
        } else if (i == (N+1)/2) {
            if (S[i-1] != '/') ok = false;
        } else {
            if (S[i-1] != '2') ok = false;
        }
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
