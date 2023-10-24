#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = gcd(a, gcd(b, c));
    cout << a/x + b/x + c/x - 3 << endl;
}
