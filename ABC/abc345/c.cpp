#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string S;
    cin >> S;
    vector<ll> cnt(26, 0);
    for (char c : S) cnt[c-'a']++;
    ll ans = 0;
    bool first = true;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 2 && first) {
            ans++;
            first = false;
        }
        for (int j = i+1; j < 26; j++) {
            ans += cnt[i] * cnt[j];
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
