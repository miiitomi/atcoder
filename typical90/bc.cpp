#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    ll P, Q;
    cin >> N >> P >> Q;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll ans = 0LL;
    for (int i = 0; i < N-4; i++) {
        for (int j = i+1; j < N-3; j++) {
            for (int k = j+1; k < N-2; k++) {
                for (int l = k+1; l < N-1; l++) {
                    for (int m = l+1; m < N; m++) {
                        ll x = 1LL;
                        x *= A[i];
                        x %= P;
                        x *= A[j];
                        x %= P;
                        x *= A[k];
                        x %= P;
                        x *= A[l];
                        x %= P;
                        x *= A[m];
                        x %= P;
                        if (x == Q) ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
