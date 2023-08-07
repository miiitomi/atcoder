#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void query(int N, map<ll, ll> &mp) {
    ll x, y;
    cin >> x >> y;
    ll d = x * x - 4 * y;
    if (d < 0) {
        cout << 0 << " ";
        return;
    }
    if (d == 0) {
        if (x % 2 != 0) {
            cout << 0 << endl;
            return;
        }
        ll a = x / 2;
        cout << (mp[a]*(mp[a]-1))/2 << " ";
        return;
    }

    ll l = 0;
    ll r = 2*pow(10LL, 9) + 2;
    while (r - l > 1) {
        ll m = (r + l)/2;
        if (m*m <= d) l = m;
        else r = m;
    }
    if (l*l != d) {
        cout << 0 << " ";
        return;
    }

    ll ans = 0;
    ll a1 = x + l;
    if (a1 % 2 == 0) {
        a1 /= 2;
        ll b1 = x - a1;
        ans += mp[a1]*mp[b1];
    }

    cout << ans << " ";
    return;
}

void solve() {
    int N;
    cin >> N;
    map<ll, ll> mp;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        mp[a]++;
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) query(N, mp);
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
