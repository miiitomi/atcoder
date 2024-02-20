// https://atcoder.jp/contests/abc221/tasks/abc221_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll ans = -1;

void solve() {
    string N;
    cin >> N;
    sort(N.begin(), N.end());
    do {
        if (N[0] == '0') continue;
        for (int i = 1; i < (int)N.size(); i++) {
            if (N[i] == '0') continue;
            ll a = 0, b = 0;
            for (int j = 0; j < i; j++) a = 10*a + (N[j] - '0');
            for (int j = i; j < (int)N.size(); j++) b = 10*b + (N[j] - '0');
            ans = max(ans, a*b);
        }

    } while (next_permutation(N.begin(), N.end()));

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
