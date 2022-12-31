// B07

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll T, N;
    cin >> T >> N;
    vector<ll> A(T+1, 0);
    for (int i = 0; i < N; i++) {
        ll l, r;
        cin >> l >> r;
        A[l]++;
        A[r]--;
    }

    cout << A[0] << endl;
    for (int t = 1; t < T; t++) {
        A[t] = A[t-1] + A[t];
        cout << A[t] << endl;
    }
}
