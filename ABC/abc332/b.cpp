#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll K, G, M;
    cin >> K >> G >> M;
    ll g = 0, m = 0;

    while (K--) {
        if (g == G) {
            g = 0;
        } else if (m == 0) {
            m = M;
        } else {
            ll x = min(m, G - g);
            m -= x;
            g += x;
        }
    }

    cout << g << " " << m << endl;
}
