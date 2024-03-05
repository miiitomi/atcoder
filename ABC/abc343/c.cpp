#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_kaibun(ll x) {
    string S;
    while (x > 0) {
        S.push_back('0' + (x % 10));
        x /= 10;
    }
    string T = S;
    reverse(T.begin(), T.end());
    return S == T;
}

void solve() {
    ll ans = 0;
    ll N;
    cin >> N;
    for (ll x = 1; x <= 1e+6; x++) {
        ll y = x * x * x;
        if (y > N) break;
        if (is_kaibun(y)) ans = y;
    }
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
