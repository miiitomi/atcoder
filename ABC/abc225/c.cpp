#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> B(N, vector<ll>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> B[i][j];
        }
    }
    ll j = ((B[0][0] - 1) % 7LL) + 1;
    ll i = ((B[0][0]-j) / 7LL) + 1;
    if (j + M - 1 > 7) {
        cout << "No" << endl;
        return 0;
    }
    for (ll k = 0; k < N; k++) {
        for (ll l = 0; l < M; l++) {
            if (B[k][l] != 7LL * (i+k-1) + (j+l)) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
