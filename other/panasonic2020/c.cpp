#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;

    if (c - a - b <= 0) {
        cout << "No" << endl;
        return 0;
    }

    ll L = 4 * a * b, R = (c-a-b)*(c-a-b);
    if (L < R) cout << "Yes" << endl;
    else cout << "No" << endl;
}
