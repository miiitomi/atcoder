#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y) {
    if (x < y) swap(x, y);
    if (y == 0) return x;
    return gcd(y, x%y);
}

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll r = gcd(a, gcd(b, c));
    cout << (a / r) - 1LL + (b / r) - 1LL + (c / r) - 1LL << endl;
}
