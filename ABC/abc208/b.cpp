#include <bits/stdc++.h>
using namespace std;

int main() {
    int P;
    cin >> P;
    int64_t M = 1LL;
    int m = 1;
    while (M <= P) {
        m++;
        M *= m;
    }
    M /= m;
    m--;

    int ans = 0;
    while (P > 0) {
        if (P >= M) {
            P -= M;
            ans++;
        } else {
            M /= m;
            m--;
        }
    }

    cout << ans << endl;
}
