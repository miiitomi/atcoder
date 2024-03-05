#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N, T;
    cin >> N >> T;
    map<ll, ll> mp;
    mp[0] = N;
    vector<ll> P(N, 0);

    while (T--) {
        ll a, b;
        cin >> a >> b;
        a--;
        ll p = P[a], q = P[a] + b;
        P[a] = q;
        mp[p]--;
        if (mp[p] == 0) mp.erase(p);
        mp[q]++;

        cout << mp.size() << "\n";
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
