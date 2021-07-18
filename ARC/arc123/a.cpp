#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t a, b, c;
    cin >> a >> b >> c;
    int64_t ans;
    if (b - a == c - b) {
        ans = 0;
    } else if (b - a < c - b) {
        if ((c + a - 2*b) % 2 == 0) {
            ans = (c + a - 2*b) / 2;
        } else {
            ans = 2 + ((c + a - 2*b) / 2);
        }
    } else {
        ans = ((2*b) - a - c);
    }

    cout << ans << endl;
}
