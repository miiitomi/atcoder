#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<pair<ll,ll>> C(N);
    for (int i = 0; i < N; i++) cin >> C[i].first;
    for (int i = 0; i < N; i++) cin >> C[i].second;
    sort(C.begin(), C.end());
    priority_queue<ll> Q;
    ll sum = 0;
    for (int i = 0; i < K; i++) {
        Q.push(C[i].second);
        sum += C[i].second;
    }
    ll ans = C[K-1].first * sum;
    for (int i = K; i < N; i++) {
        sum += C[i].second;
        Q.push(C[i].second);
        sum -= Q.top();
        Q.pop();
        ans = min(ans, C[i].first * sum);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
