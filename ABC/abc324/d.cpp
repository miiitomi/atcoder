#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
    int N;
    string S;
    cin >> N >> S;
    sort(S.begin(), S.end());
    ll max_v = 0;
    ll p = 1;
    vector<int> v(10, 0);
    for (int i = 0; i < N; i++) {
        max_v += p * (ll)(S[i]-'0');
        p *= 10;
        v[(int)(S[i]-'0')]++;
    }

    ll ans = 0;

    for (ll x = 0; x*x <= max_v; x++) {
        ll y = x*x;
        vector<int> w(10, 0);
        for (int i = 0; i < N; i++) {
            w[y % 10]++;
            y /= 10;
        }
        if (v == w) ans++;
    }

    cout << ans << endl;
}
