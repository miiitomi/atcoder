#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll N;
    cin >> N;
    vector<ll> cnt(N+1, 0);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }

    vector<ll> divisible_pairs(N+1, 0);
    for (ll x = 1; x <= N; x++) {
        divisible_pairs[x] = cnt[x]*(cnt[x]-1)/2;
        ll c = cnt[x];
        for (ll y = 2*x; y <= N; y += x) {
            divisible_pairs[x] += cnt[y]*(cnt[y]-1)/2;
            divisible_pairs[x] += c*cnt[y];
            c += cnt[y];
        }
    }

    vector<ll> gcd_pairs(N+1, 0);
    for (ll x = N; x >= 1; x--) {
        gcd_pairs[x] = divisible_pairs[x];
        for (ll y = 2*x; y <= N; y += x) gcd_pairs[x] -= gcd_pairs[y];
    }

    vector<bool> is_in(N+1, false);
    for (ll x = 1; x <= N; x++) {
        if (cnt[x] > 0) {
            for (ll y = x; y <= N; y += x) is_in[y] = true;
        }
    }

    ll ans = N*(N-1)/2;
    for (ll x = 1; x <= N; x++) {
        if (is_in[x]) ans -= gcd_pairs[x];
    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
