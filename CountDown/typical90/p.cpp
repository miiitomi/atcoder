#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, A, B, C;
    cin >> N >> A >> B >> C;

    ll tmp = 1e+9;
    for (ll x = 0; x <= 9999; x++) {
        if (A*x > N) break;
        for (ll y = 0; x+y <= 9999; y++) {
            if (A*x+B*y > N) break;
            if ((N-(A*x+B*y)) % C == 0) {
                ll z = (N-(A*x+B*y)) / C;
                tmp = min(tmp, x+y+z);
            }
        }
    }
    cout << tmp << endl;
}
