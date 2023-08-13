#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    ll ans = -1;

    for (int i = N; i >= 0; i--) {
        ll tmp = 0;
        int max_v = -1;

        for (int j = 1; j <= N; j++) {
            if (j <= i) {
                tmp += j * j;
                max_v = max(j*j, max_v);
            } else if (i < j) {
                tmp += j * (N + 1 - (j - i));
                max_v = max(max_v, j * (N + 1 - (j - i)));
            }
        }
        tmp -= max_v;
        ans = max(ans, tmp);
    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();
}
