// https://atcoder.jp/contests/abc210/tasks/abc210_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int H, W;
ll C;

ll solve(vector<vector<ll>> &A) {
    ll ans = 1e+18;
    vector<vector<ll>> V(H, vector<ll>(W, 1e+18));

    for (int i = H-1; i >= 0; i--) {
        for (int j = W-1; j >= 0; j--) {
            if (i < H-1) V[i][j] = min(V[i][j], V[i+1][j]);
            if (j < W-1) V[i][j] = min(V[i][j], V[i][j+1]);
            ans = min(ans, A[i][j] - C*(i+j) + V[i][j]);
            V[i][j] = min(V[i][j], A[i][j] + C*(i+j));
        }
    }

    return ans;
}

int main() {
    cin >> H >> W >> C;
    vector<vector<ll>> A(H, vector<ll>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> A[i][j];
    }

    ll ans = solve(A);
    for (int i = 0; i < H; i++) reverse(A[i].begin(), A[i].end());
    ans = min(ans, solve(A));

    cout << ans << endl;    
}
