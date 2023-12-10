#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N), P(N), r(N, 0);
    vector<vector<int>> v;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 1; i < N; i++) {
        cin >> P[i];
        P[i]--;
        r[i] = r[P[i]] + 1;
    }

    vector<ll> B(N, 0);
    for (int i = 0; i < N; i++) {
        B[r[i]] += A[i];
    }

    for (int j = N-1; j >= 0; j--) {
        if (B[j] > 0) {
            cout << '+' << endl;
            return 0;
        } else if (B[j] < 0) {
            cout << '-' << endl;
            return 0;
        }
    }
    cout << '0' << endl;
}
