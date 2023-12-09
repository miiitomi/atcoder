// https://atcoder.jp/contests/abc196/tasks/abc196_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    set<ll> S;
    for (ll x = 1; x <= 1e+6; x++) {
        string y = "";
        for (int k = 0; k < 2; k++) {
            ll z = x;
            while (z > 0) {
                y.push_back((char)('0' + z % 10));
                z /= 10;
            }
        }

        ll z = 0;
        while (!y.empty()) {
            char c = y.back();
            y.pop_back();
            z = 10*z + (int)(c - '0');
        }

        if (z <= N) S.insert(z);
    }

    cout << S.size() << endl;
}
