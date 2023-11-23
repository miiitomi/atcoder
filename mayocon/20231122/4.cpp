// https://atcoder.jp/contests/abc142/tasks/abc142_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B;
    cin >> A >> B;
    ll G = gcd(A, B);
    vector<ll> p{1};
    for (ll x = 2; x*x <= G; x++) {
        if (G % x == 0) {
            p.push_back(x);
            while (G % x == 0) G /= x;
        }
    }

    if (G != 1) p.push_back(G);
    cout << p.size() << endl;
}
