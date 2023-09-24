#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll in_subtree(ll n, ll x, ll k) {
    if (k < 0) return 0;
    ll left = x, right = x;
    for (int i = 0; i < k; i++) {
        left = 2*left;
        right = 2 * right + 1;
        if (n < left) return  0;
    }
    return (min(right, n) - left + 1);
}

void solve() {
    ll N, X, K;
    cin >> N >> X >> K;

    ll ans = 0;

    ans += in_subtree(N, X, K);

    while (X > 1 && K > 0) {
        if (X % 2 == 0) ans += in_subtree(N, X+1, K-2);
        else ans += in_subtree(N, X-1, K-2);
        X = X / 2;
        K--;
        if (X >= 1 && K == 0) ans++;
    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();    
}
