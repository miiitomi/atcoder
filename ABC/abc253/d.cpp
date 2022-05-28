#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll N, ll x) {
    ll c =  N / x;
    return (c * (c+1) / 2) * x;
}

int main() {
    ll N, A, B;
    cin >> N >> A >> B;
    ll C = lcm(A, B);

    ll ans = (N+1) * N / 2;
    ans -= f(N, A);
    ans -= f(N, B);
    ans += f(N, C);
    cout << ans << endl;
}
