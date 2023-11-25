#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    vector<ll> r(N, 0), c(N, 0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'o') {
                r[i]++;
                c[j]++;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] == 'o') {
                ans += (r[i] - 1)*(c[j] - 1);
            }
        }
    }

    cout << ans << endl;
}
