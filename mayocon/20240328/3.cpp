// https://atcoder.jp/contests/abc233/tasks/abc233_d
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), S(N+1, 0);
    map<ll, ll> mp;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        S[i+1] = S[i] + A[i];
        mp[S[i+1]]++;
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (mp.count(K)) ans += mp[K];
        K += A[i];
        mp[S[i+1]]--;
        if (mp[S[i+1]] == 0) mp.erase(S[i+1]);
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
