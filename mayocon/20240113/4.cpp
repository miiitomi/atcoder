// https://atcoder.jp/contests/abc320/tasks/abc320_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> ans(N, 0);
    set<ll> st;
    for (int i = 0; i < N; i++) st.insert(i);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    while (M--) {
        ll T, W, S;
        cin >> T >> W >> S;
        while (!pq.empty() && pq.top().first <= T) {
            st.insert(pq.top().second);
            pq.pop();
        }

        if (st.empty()) continue;

        ll i = *st.begin();
        st.erase(i);
        ans[i] += W;
        pq.push(make_pair(T+S, i));
    }

    for (ll w : ans) cout << w << "\n";
}
