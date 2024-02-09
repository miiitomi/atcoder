#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<bool>> S(1000, vector<bool>(1000, false));

void solve() {
    ll n;
    string t;
    cin >> n >> t;
    int m = 0, b = 1;
    for (int k = 0; k < 3; k++) {
        m += b * (int)(t[(int)t.size()-1-k] - '0');
        b *= 10;
    }

    ll ans = 0;
    for (int i = 1; i <= min(n, 999LL); i++) {
        ans += S[i][m];
    }
    if (n >= 1000) ans += n - 999;
    cout << ans << "\n";
}

int main() {
    for (int i = 1; i <= 999; i++) {
        for (int j = 0; j < i; j++) {
            int x = (j * 1000) / i;
            S[i][x] = true;
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
