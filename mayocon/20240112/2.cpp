// https://atcoder.jp/contests/abc097/tasks/abc097_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll X;
    cin >> X;
    set<ll> S;
    for (ll a = 1; a <= X; a++) {
        ll b = a*a;
        while (b <= X) {
            S.insert(b);
            b *= a;
            if (a == 1) break;
        }
    }
    cout << *S.rbegin() << endl;
}
