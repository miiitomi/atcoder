#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll N2, ll N3, ll N4) {
    ll ans = 0LL;
    ll N4_new, N3_new, N2_new;

    ans += min(N3/2, N4);
    N4_new = N4 - min(N3/2, N4);
    N3_new = N3 - 2 * min(N3/2, N4);
    N4 = N4_new;
    N3 = N3_new;

    ans += min(N3/2, N2/2);
    N3_new = N3 - 2 * min(N3/2, N2/2);
    N2_new = N2 - 2 * min(N3/2, N2/2);
    N3 = N3_new;
    N2 = N2_new;

    ans += min(N4/2, N2);
    N4_new = N4 - 2 * min(N4/2, N2);
    N2_new = N2 - min(N4/2, N2);
    N4 = N4_new;
    N2 = N2_new;

    ans += min(N4, N2/3);
    N4_new = N4 - min(N4, N2/3);
    N2_new = N2 - 3*min(N4, N2/3);
    N2 = N2_new;

    ans += N2/5;

    return ans;
}

int main() {
    int T;
    cin >> T;
    vector<ll> V(T);
    for (int i = 0; i < T; i++) {
        ll N2, N3, N4;
        cin >> N2 >> N3 >> N4;
        V[i] = f(N2, N3, N4);
    }
    for (ll v : V) {
        cout << v << endl;
    }
}
