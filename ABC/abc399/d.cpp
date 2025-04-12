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
    vector<int> A(2*N);
    vector<bool> adj(N, false);
    map<pair<int,int>, vector<int>> mp;
    for (int i = 0; i < 2*N; i++) {
        cin >> A[i];
        A[i]--;
        if (i > 0) {
            if (A[i-1] == A[i]) {
                adj[A[i]] = true;
            } else {
                mp[make_pair(min(A[i-1], A[i]), max(A[i-1], A[i]))].push_back(i);
            }
        }
    }
    int ans = 0;
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        if (iter->second.size() < 2 || abs(iter->second.front() - iter->second.back()) <= 1) continue;
        auto [i, j] = iter->first;
        if (adj[i] || adj[j]) continue;
        ans++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
