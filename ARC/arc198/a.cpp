#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;

void solve() {
    int N;
    cin >> N;

    if (N <= 3) {
        cout << 1 << "\n";
        cout << N << "\n";
    } else {
        cout << N/2 << "\n";
        for (int x = 2; x <= N; x += 2) cout << x << " ";
        cout << "\n";
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
