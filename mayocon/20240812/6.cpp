// https://atcoder.jp/contests/abc116/tasks/abc116_d
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
    vector<ll> t(N), d(N);
    priority_queue<pair<ll,ll>> PQL;
    for (int i = 0; i < N; i++) {
        cin >> t[i] >> d[i];
        t[i]--;
        PQL.push({d[i], t[i]});
    }
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> PQS;
    vector<ll> cnt(N, 0);
    ll num_type = 0;
    ll ans = 0;
    for (int k = 0; k < K; k++) {
        auto p = PQL.top();
        PQL.pop();
        ans += p.first;
        cnt[p.second]++;
        if (cnt[p.second] == 1) num_type++;
        PQS.push(p);
    }
    ans += num_type*num_type;
    ll tmp = ans;
    while (!PQL.empty() && num_type < K) {
        auto p = PQL.top();
        PQL.pop();
        if (cnt[p.second] > 0) continue;
        auto q = PQS.top();
        PQS.pop();
        while (cnt[q.second] == 1) {
            q = PQS.top();
            PQS.pop();
        }
        tmp -= num_type*num_type;
        tmp -= q.first;
        tmp += p.first;
        cnt[q.second]--;
        cnt[p.second]++;
        num_type++;
        tmp += num_type*num_type;
        ans = max(ans, tmp);
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
