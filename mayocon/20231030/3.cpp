// https://atcoder.jp/contests/abc070/tasks/abc070_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;

    ll ans = 1;
    for (int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        ans = lcm(ans, a);
    }

    cout << ans << endl;
}
