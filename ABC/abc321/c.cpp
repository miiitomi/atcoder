#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int K;
    cin >> K;

    vector<ll> S;
    S.reserve(1e+5);


    for (int s = 1; s < (1 << 10); s++) {
        ll x = 0;
        for (int k = 9; k >= 0; k--) {
            if (s & (1 << k)) {
                x *= 10;
                x += k;
            }
        }
        S.push_back(x);
    }

    sort(S.begin(), S.end());
    cout << S[K] << endl;
}
