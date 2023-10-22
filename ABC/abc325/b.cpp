#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> W(N), X(N);
    for (int i = 0; i < N; i++) cin >> W[i] >> X[i];

    ll ans = -1;
    for (int i = 0; i <= 23; i++) {
        ll tmp = 0;
        for (int j = 0; j < N; j++) {
            if (9 <= (X[j] + i) % 24 && (X[j] + i) % 24 <= 17) {
                tmp += W[j];
            }
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;
}
