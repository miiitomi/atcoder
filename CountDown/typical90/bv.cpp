#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    string S;
    cin >> N >> S;
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        if (S[i] == 'b') ans += (1LL << i);
        else if (S[i] == 'c') ans += (1LL << i) * 2;
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
