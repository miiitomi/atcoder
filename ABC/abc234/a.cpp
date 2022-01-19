#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x) {
    return (x*x) + 2*x + 3;
}

int main() {
    ll t;
    cin >> t;
    cout << f(f(f(t) + t) + f(f(t))) << endl;
}
