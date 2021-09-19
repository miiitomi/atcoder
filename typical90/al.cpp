#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = 1000000000000000000LL;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ll A, B;
    cin >> A >> B;
    ll g = gcd(A, B);
    ll m = INF / (A/g);
    if (m < B) cout << "Large" << endl;
    else cout << (A/g)*B << endl;
}
