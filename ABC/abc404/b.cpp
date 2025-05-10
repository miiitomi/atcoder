#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int f(vector<string> &S, vector<string> &T) {
    int N = S.size();
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (S[i][j] != T[i][j]) ans++;
        }
    }
    return ans;
}

void rotate(vector<string> &S) {
    vector<string> T = S;
    int N = S.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            T[j][N-1-i] = S[i][j];
        }
    }
    swap(S, T);
}

void solve() {
    int N;
    cin >> N;
    vector<string> S(N), T(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) cin >> T[i];
    int ans = 1e+9;
    for (int k = 0; k < 4; k++) {
        int tmp = f(S, T) + k;
        ans = min(ans, tmp);
        rotate(S);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
