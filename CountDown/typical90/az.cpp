#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

int main() {
    int N;
    cin >> N;
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ll tmp = 0;
        for (int j = 0; j < 6; j++) {
            ll a;
            cin >> a;
            tmp += a;
        }
        ans = ans * tmp % MOD;
    }
    cout << ans << endl;
}
