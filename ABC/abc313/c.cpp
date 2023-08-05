#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll s = 0;
    for (ll a : A)  s += a;
    ll M = s / N;

    ll a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] > M+1) {
            a += A[i] - (M+1);
        }
        if (A[i] > M) {
            c += A[i] - M;
        }
        if (A[i] < M) {
            b += M - A[i];
        }
        if (A[i] < M-1) {
            d += M-1 - A[i];
        }
    }

    cout << min(max(a, b), max(c, d)) << endl;
}
