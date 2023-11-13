// https://atcoder.jp/contests/abc161/tasks/abc161_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v{-1, 0, 1};

int main() {
    int K;
    cin >> K;

    queue<ll> Q;
    for (ll x = 1; x <= 9; x++) {
        Q.push(x);
        K--;
        if (K == 0) {
            cout << x << endl;
            return 0;
        }
    }

    while (!Q.empty()) {
        ll x = Q.front();
        Q.pop();
        ll s = x % 10;
        x *= 10;

        for (int i = 0; i < 3; i++) {
            ll t = s + v[i];
            if (0 <= t && t <= 9) {
                K--;
                ll y = x + t;
                Q.push(y);
                if (K == 0) {
                    cout << y << endl;
                    return 0;
                }
            }
        }
    }
}
