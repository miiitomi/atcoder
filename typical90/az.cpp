#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(6));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) cin >> A[i][j];
    }
    ll ans = 1LL;
    for (int i = 0; i < N; i++) {
        ll s = 0LL;
        for (int j = 0; j < 6; j++) s += A[i][j];
        ans *= s;
        ans %= MOD;
    }
    cout << ans << endl;
}
