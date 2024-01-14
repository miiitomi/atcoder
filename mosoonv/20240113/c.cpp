// https://atcoder.jp/contests/abc039/tasks/abc039_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll X;
    cin >> X;
    for (ll n = 1; n <= X; n++) {
        ll Y = n*n*n*n;
        if (X == Y) {
            cout << n << endl;
            return 0;
        }
    }
}
