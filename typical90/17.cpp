// https://atcoder.jp/contests/typical90/tasks/typical90_q
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll,ll>> L(M);
    for (int i = 0; i < M; i++) {
        cin >> L[i].first >> L[i].second;
        L[i].first--;
        L[i].second--;
    }
    sort(L.begin(), L.end(), [](const pair<ll,ll> &l, const pair<ll,ll> &r){
        if (l.first != r.first) return l.first < r.first;
        else return l.second > r.second;
    });
    fenwick_tree<ll> fw(N);
    ll ans = M*(M-1)/2;
    for (int i = 0; i < M; i++) {
        ans -= fw.sum(0, L[i].first+1) + fw.sum(L[i].second, N);
        fw.add(L[i].second, 1);
    }
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
