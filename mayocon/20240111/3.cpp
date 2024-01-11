// https://atcoder.jp/contests/abc195/tasks/abc195_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll A, B, W;
    cin >> A >> B >> W;
    W *= 1000;

    ll minv = 1e+9, maxv = -1e+9;
    for (ll i = 1; i <= W; i++) {
        if (i*A <= W && W <= i*B) {
            minv = min(minv, i);
            maxv = max(maxv, i);
        }
    }

    if (maxv >0) cout << minv << " " << maxv << endl;
    else cout << "UNSATISFIABLE" << endl;
}

