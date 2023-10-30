#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N), X(Q);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < Q; i++) cin >> X[i];

    vector<ll> B(31, 0), C(31, 0), T(31, 1);
    for (ll x = 1; x <= 30; x++) {
        B[x] = x;
        T[x] = T[x-1] * 2;
    }

    for (int q = 0; q < Q; q++) {
        ll x = X[q];
        for (int y = 1; y <= 30; y++) {
            if (B[y] >= x) {
                B[y] = x-1;
                C[y] += T[x-1];
            }
        }
    }

    for (ll a : A) {
        ll x = 0;
        while (x <= 30 && a % T[x] == 0) x++;
        x--;
        cout << a + C[x] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
