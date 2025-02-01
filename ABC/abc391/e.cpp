#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll N;
vector<vector<int>> A;

ll rec(int i, int j) {
    if (i == 0) return 1;
    int t = 1 - A[i][j];
    vector<int> cnt(3, 0);
    for (int k = 0; k < 3; k++) {
        if (A[i-1][3*j + k] != t) {
            cnt[k] = rec(i-1, 3*j+k);
        }
    }
    sort(cnt.begin(), cnt.end());
    return cnt[0]+cnt[1];
}

void solve() {
    cin >> N;
    ll k = 1;
    for (int i = 0; i < N; i++) k *= 3;
    A.assign(1, vector<int>(k, 0));
    for (int i = 0; i < k; i++) {
        char c;
        cin >> c;
        if (c == '1') A[0][i] = 1;
    }
    int s = 0;
    while ((int)A[s].size() > 1) {
        int m = A[s].size();
        A.push_back(vector<int>(m/3, 0));
        for (int i = 0; i < m/3; i++) {
            int cnt = 0;
            for (int j = 3*i; j < 3*(i+1); j++) cnt += A[s][j];
            if (cnt >= 2) A[s+1][i] = 1;
        }
        s++;
    }
    ll ans = rec(A.size()-1, 0);
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
