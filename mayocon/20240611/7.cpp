// https://atcoder.jp/contests/abc337/tasks/abc337_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> cnt(N, 0), C(2*N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        C[i]--;
        C[N+i] = C[i];
        cnt[C[i]]++;
    }

    vector<ll> tmp(N, 0);
    ll ans = 0;
    int r = 0, sum = 0;
    for (int l = 0; l <= N-1; l++) {
        while (sum < M && r < 2*N) {
            ll c = C[r];
            tmp[c]++;
            if ((tmp[c]+K-1)/K != (tmp[c]-1+K-1)/K) {
                sum++;
                ans += min(((tmp[c]+K-1)/K)*K, cnt[c]) - min(((tmp[c]-1+K-1)/K)*K, cnt[c]);
            }
            r++;
        }
        cout << ans << "\n";

        ll c = C[l];
        tmp[c]--;
        if ((tmp[c]+K-1)/K != (tmp[c]+1+K-1)/K) {
            sum--;
            ans += min(((tmp[c]+K-1)/K)*K, cnt[c]) - min((((tmp[c]+1+K-1)/K))*K, cnt[c]);
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
