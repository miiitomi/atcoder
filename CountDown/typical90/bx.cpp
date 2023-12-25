#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N), S(2*N+1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= 2*N; i++) {
        S[i] = S[i-1] + A[(i-1) % N];
    }

    if (S[N] % 10 != 0) {
        cout << "No" << endl;
        return 0;
    }
    ll x = S[N] / 10;

    for (int i = 0; i < N; i++) {
        int l = i, r = 2*N+1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            ll y = S[m] - S[i];
            if (y > x) r = m;
            else l = m;
        }
        if (S[l] - S[i] == x) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
