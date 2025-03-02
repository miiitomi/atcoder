#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    int N;
    cin >> N;
    vector<int> K(N);
    vector<vector<int>> A(N);
    vector<vector<double>> p(N, vector<double>(100000, 0));
    for (int i = 0; i < N; i++) {
        cin >> K[i];
        for (int j = 0; j < K[i]; j++) {
            int x;
            cin >> x;
            x--;
            A[i].push_back(x);
            p[i][x] += 1.0/K[i];
        }
        sort(A[i].begin(), A[i].end());
        A[i].erase(unique(A[i].begin(), A[i].end()), A[i].end());
    }

    double ans = -INF;
    for (int i = 1; i < N; i++) {
        vector<double> tmp(i, 0);
        for (int a : A[i]) {
            for (int j = 0; j < i; j++) {
                tmp[j] += p[j][a]*p[i][a];
            }
        }
        ans = max(ans, *max_element(tmp.begin(), tmp.end()));
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
