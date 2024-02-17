// https://atcoder.jp/contests/abc295/tasks/abc295_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string S;
    cin >> S;
    vector<ll> cnt((1 << 10), 0);

    int s = 0;
    cnt[s]++;

    int N = S.size();

    for (int i = 0; i < N; i++) {
        int x = S[i] - '0';
        s ^= (1 << x);
        cnt[s]++;
    }

    ll ans = 0;

    for (int t = 0; t < (1 << 10); t++) {
        ll n = cnt[t];
        ans += n*(n-1)/2;
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
