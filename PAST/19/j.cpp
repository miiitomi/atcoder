// https://atcoder.jp/contests/past19-open/tasks/past19_j
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N;
vector<ll> A;
ll ans = INF;

void f(vector<vector<int>> V, vector<int> R) {
    if (R.empty()) {
        ll ma = -INF, mi = INF;
        for (auto &v : V) {
            ll tmp = A[v[0]]+A[v[1]]+A[v[2]];
            ma = max(ma, tmp);
            mi = min(mi, tmp);
        }
        ans = min(ans, ma - mi);
        return;
    }
    for (int i = 1; i < (int)R.size(); i++) {
        for (int j = i+1; j < (int)R.size(); j++) {
            vector<int> v{R[0], R[i], R[j]};
            vector<int> K = R;
            K.erase(find(K.begin(), K.end(), R[0]));
            K.erase(find(K.begin(), K.end(), R[i]));
            K.erase(find(K.begin(), K.end(), R[j]));
            V.push_back(v);
            f(V, K);
            V.pop_back();
        }
    }
}

void solve() {
    cin >> N;
    A.resize(3*N);
    for (int i = 0; i < 3*N; i++) cin >> A[i];
    vector<vector<int>> V;
    vector<int> R(3*N);
    iota(R.begin(), R.end(), 0);
    f(V, R);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
