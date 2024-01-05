// https://atcoder.jp/contests/abc166/tasks/abc166_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    map<ll, ll> mp;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if (mp.count(i-a)) ans += mp[i - a];
        mp[i + a]++;
    }
    cout << ans << endl;
}
