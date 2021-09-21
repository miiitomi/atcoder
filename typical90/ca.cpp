#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<ll>> A(H, vector<ll>(W)), B(H, vector<ll>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> A[i][j];
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> B[i][j];
    }
    ll ans = 0LL;
    for (int i = 0; i < H-1; i++) {
        for (int j = 0; j < W-1; j++) {
            ll d = B[i][j] - A[i][j];
            ans += abs(d);
            A[i][j] += d;
            A[i][j+1] +=  d;
            A[i+1][j] += d;
            A[i+1][j+1] += d;
        }
    }
    if (A == B) {
        cout << "Yes" << endl;
        cout << ans << endl;
    } else {
        cout << "No" << endl;
    }
}
