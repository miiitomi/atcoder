#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, a, b, x;
    cin >> s >> a >> b >> x;
    int ans = 0, tmp = 0;
    while (true) {
        for (int k = 0; k < a+b; k++) {
            tmp += 1;
            if (k < a) ans += s;
            if (tmp == x) {
                cout << ans << "\n";
                return 0;
            }
        }
    }
}
