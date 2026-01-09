#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> cnt(N, 0);
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        a--;
        cnt[a]++;
    }
    ll ans = 0;
    for (ll a = 0; a < N; a++) {
        ll n = cnt[a];
        ans += (n*(n-1)/2)*(N-n);
    }
    cout << ans << "\n";
}
