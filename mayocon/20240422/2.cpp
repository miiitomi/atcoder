// https://atcoder.jp/contests/abc221/tasks/abc221_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string N;
    cin >> N;
    sort(N.begin(), N.end());
    int M = N.size();
    ll ans = -1;
    do {
        if (N[0] == 0) continue;
        for (int i = 1; i < M; i++) {
            if (N[i] == 0) continue;
            ll a = 0, b = 0;
            for (int k = 0; k < i; k++) {
                a = a*10 + (N[k] - '0');
            }
            for (int k = i; k < M; k++) {
                b = b*10 + (N[k] - '0');
            }
            ans = max(ans, a*b);
        }
    } while (next_permutation(N.begin(), N.end()));

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
