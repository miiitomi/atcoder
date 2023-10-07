#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;

    map<ll, ll> M;
    for (int i = 0; i < N; i++) {
        ll s, c;
        cin >> s >> c;
        M[s] = c;
    }

    ll ans = 0;
    for (auto iter = M.begin(); iter != M.end(); iter++) {
        ll s = iter->first;
        ll c = iter->second;

        ll x = c / 2;
        c -= x*2;

        M[2*s] += x;
        ans += c;
    }

    cout << ans << endl;
}
