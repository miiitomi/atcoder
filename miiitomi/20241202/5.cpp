// https://atcoder.jp/contests/abc255/tasks/abc255_f
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int N;
vector<int> P, I, J;
vector<pair<int,int>> ans;

bool f(int l, int r, int s, int t) {
    int x = P[l];
    int u = J[x];
    if (!(s <= u && u < t)) return false;

    int k = u - s;
    if (k > 0) {
        int y = P[l+1];
        ans[x].first = y+1;
        if (!f(l+1, l+1+k, s, s+k)) return false;
    }

    int m = t - u - 1;
    if (m <= 0) return true;
    int z = P[l+1+k];
    ans[x].second = z+1;
    if (!f(l+1+k, l+1+k+m, u+1, u+1+m)) return false;
    return true;
}

void solve() {
    cin >> N;
    P.resize(N);
    I.resize(N);
    J.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--;
    }
    for (int i = 0; i < N; i++) {
        cin >> I[i];
        I[i]--;
        J[I[i]] = i;
    }
    if (P[0] != 0) {
        cout << -1 << endl;
        return;
    }
    ans.assign(N, {0, 0});
    if (f(0, N, 0, N)) {
        for (int i = 0; i < N; i++) {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
