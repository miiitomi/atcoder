#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];

    ll left = 0; // NG
    ll right = 1e+18; // OK

    while (right - left > 1) {
        ll mid = (right + left) / 2;

        ll K = mid;
        ll count = 1;
        bool ok = true;
        for (ll l : L) {
            if (l > mid) {
                ok = false;
                break;
            }
            if (l <= K) K -= l;
            else {
                count++;
                K = mid;
                K -= l;
            }
            if (K > 0) K--;
        }

        if (ok && count <= M) right = mid;
        else left = mid;
    }

    cout << right << endl;
}
