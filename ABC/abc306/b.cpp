#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
    ull ans = 0;
    ull x = 1;

    for (int i = 0; i < 64; i++) {
        ull a;
        cin >> a;
        ans += a * x;
        x *= 2LL;
    }
    cout << ans << endl;
}
