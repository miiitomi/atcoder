#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll X, K;
    cin >> X >> K;

    while (true) {
        ll x = X;
        ll Y = 0;
        while (x > 0) {
            Y += x % 10;
            x /= 10;
        }
        if (Y % K == 0) {
            cout << X << endl;
            return;
        }
        X++;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
