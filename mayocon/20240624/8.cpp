// https://atcoder.jp/contests/abc215/tasks/abc215_g
#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;

vector<mint> F(1e+6, 1);
mint C(int n, int r) {
    if (n < r) return 0;
    return F[n]/(F[n-r]*F[r]);
};

void solve() {
    int N;
    cin >> N;
    vector<int> c(N), v;
    for (int i = 0; i < N; i++) {
        cin >> c[i];
        v.push_back(c[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int &x : c) x = distance(v.begin(), lower_bound(v.begin() ,v.end(), x));
    vector<int> cnt(v.size(), 0);
    for (int &x : c) cnt[x]++;
    vector<int> tmp(N+1, 0);
    for (int i = 0; i < (int)v.size(); i++) tmp[cnt[i]]++;
    v = {};
    for (int i = 0; i <= N; i++) if (tmp[i] > 0) v.push_back(i);

    for (int K = 1; K <= N; K++) {
        mint ans = 0;
        mint p = C(N, K).inv();
        for (int l : v) {
            mint t = 1 - C(N-l, K)*p;
            ans += t * tmp[l];
        }
        cout << ans.val() << "\n";
    }
}

int main() {
    for (int x = 1; x < (int)1e+6; x++) F[x] = F[x-1]*x;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
