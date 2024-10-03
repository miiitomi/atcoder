// https://atcoder.jp/contests/abc079/tasks/abc079_c
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    vector<int> V(4);
    for (int k = 0; k < 4; k++) {
        char c;
        cin >> c;
        V[k] = c-'0';
    }
    for (int s = 0; s < (1 << 3); s++) {
        int tmp = V[0];
        for (int i = 0; i < 3; i++) {
            if (s & (1 << i)) tmp += V[i+1];
            else tmp -= V[i+1];
        }
        if (tmp == 7) {
            cout << V[0];
            for (int k = 0; k < 3; k++) {
                if (s & (1 << k)) cout << '+';
                else cout << '-';
                cout << V[k+1];
            }
            cout << "=7\n";
            return;
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
