// https://atcoder.jp/contests/abc114/tasks/abc114_c
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N;
set<ll> S;

void dfs(ll n, ll san, ll go, ll nana) {
    if (n > N) return;
    if (san > 0 && go > 0 && nana > 0) S.insert(n);
    
    dfs(n*10LL + 3, san+1, go, nana);
    dfs(n*10LL + 5, san, go+1, nana);
    dfs(n*10LL + 7, san, go, nana+1);
}

void solve() {
    cin >> N;
    dfs(0, 0, 0, 0);
    cout << S.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
