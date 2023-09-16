#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod_pow(ll a, ll n) {
    if (n == 0) return 1;
    ll res = mod_pow(a, n/2);
    if (n % 2 == 1) return res * res * a;
    else return res * res;
}

int main() {
    ll A, B;
    cin >> A >> B;

    cout << mod_pow(A, B) + mod_pow(B, A) << endl;
}
