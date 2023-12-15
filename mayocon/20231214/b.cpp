// https://atcoder.jp/contests/abc055/tasks/abc055_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e+9 + 7;

int main() {
    ll N;
    cin >> N;
    ll x = 1LL;
    for (ll i = 1; i <= N; i++) {
        x = x * i % MOD;
    }
    cout << x << endl;
}
