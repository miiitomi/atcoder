// https://atcoder.jp/contests/abc117/tasks/abc117_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    ll ans = 0;
    ll x = 0;
    for (ll k = 40; k >= 0; k--) {
        if (x + (1LL << k) > K) {
            ll cnt1 = 0;
            for (ll a : A) if (a & (1LL << k)) cnt1++;
            ans += cnt1 * (1LL << k);
        } else {
            ll cnt0 = 0, cnt1 = 0;
            for (ll a : A) {
                if (a & (1LL << k)) cnt1++;
                else cnt0++;
            }
            if (cnt1 >= cnt0) {
                ans += cnt1 * (1LL << k);
            } else {
                ans += cnt0 * (1LL << k);
                x += (1LL << k);
            }
        }
    }

    cout << ans << endl;
}
