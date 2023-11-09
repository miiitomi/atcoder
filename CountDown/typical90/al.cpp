#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b;
    cin >> a >> b;
    ll c = gcd(a, b);
    a /= c;
    if (b <= ((ll)1e+18) / a) {
        cout << a*b << endl;
    } else {
        cout << "Large" << endl;        
    }
}
