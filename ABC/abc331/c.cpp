#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B;
    for (int i = 0; i < N; i++) cin >> A[i];
    B = A;
    sort(B.begin(), B.end());
    vector<ll> S(1e+6 + 1, 0);
    ll tmp = 0;

    for (ll x = 1e+6; x >= 0; x--) {
        while (!B.empty() && B.back() > x) {
            tmp += B.back();
            B.pop_back();
        }
        S[x] = tmp;
    }

    for (int i = 0; i < N; i++) {
        cout << S[A[i]] << " ";
    }
    cout << endl;
}
