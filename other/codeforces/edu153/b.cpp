#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll M, K, a1, ak;
    cin >> M >> K >> a1 >> ak;

    M -= K * min(M/K, ak);

    
    ll s = min(M%K, a1);
    M -= s;
    a1 -= s;

    if (M == 0) {
        cout << 0 << endl;
        return;
    }

    ll m = min(M, K*(a1/K));
    M -= m;
    a1 -= m;

    ll ans1 = M/K + M%K;
    M -= min(M, a1);
    ll ans2 = M/K + M%K;

    cout << min(ans1, ans2) << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
