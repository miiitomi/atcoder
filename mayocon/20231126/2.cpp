// https://atcoder.jp/contests/abc209/tasks/abc209_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

int main() {
    ll N;
    cin >> N;
    vector<ll> C(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(C.begin(), C.end());

    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ans = ans * (C[i] - i) % MOD;
    }

    cout << ans << endl;
}
