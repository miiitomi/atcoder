#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, sum = 0;
    cin >> N;
    vector<ll> A(2*N);
    set<int> st;
    for (int i = 0; i < 2*N; i++) {
        cin >> A[i];
        sum += A[i];
        st.insert(i);
    }
    priority_queue<pair<ll,pair<ll,ll>>, vector<pair<ll,pair<ll,ll>>>, greater<pair<ll,pair<ll,ll>>>> Q;
    for (int i = 0; i < 2*N-1; i++) {
        Q.push({A[i+1], {i, i+1}});
    }
    vector<bool> remain(2*N, true);
    int num_remain = 2*N;
    while (num_remain) {
        auto [c, p] = Q.top();
        Q.pop();
        if (!remain[p.first] || !remain[p.second]) continue;
        sum -= c;
        auto iter = st.lower_bound(p.first);
        auto iter2 = st.lower_bound(p.second);
        iter2++;
        if (iter != st.begin() && iter2 != st.end()) {
            iter--;
            ll a = *iter, b = *iter2;
            Q.push({A[b], {a, b}});
        }
        remain[p.first] = false;
        remain[p.second] = false;
        st.erase(p.first);
        st.erase(p.second);
        num_remain-=2;
    }

    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
