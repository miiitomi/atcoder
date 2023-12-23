#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> R(N);
    for (int i = 0; i < N; i++) cin >> R[i];
    sort(R.begin(), R.end());
    vector<ll> c(N+1, 0);
    for (int i = 0; i < N; i++) c[i+1] = c[i] + R[i];

    while (Q--) {
        ll x;
        cin >> x;
        cout << -1 + (ll)distance(c.begin(), lower_bound(c.begin(), c.end(), x+1)) << "\n";
    }
}
