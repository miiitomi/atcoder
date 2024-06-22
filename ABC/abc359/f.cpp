#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    ll ans = 0;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q;
    vector<ll> cnt(N, 1);
    ll r = N-2;
    for (int i = 0; i < N; i++) {
        ans += A[i];
        Q.push({A[i]*(2*2-1), i});
    }
    while (r--) {
        pair<ll,ll> p = Q.top();
        Q.pop();
        int i = p.second;
        ans += p.first;
        cnt[i]++;
        ll c = cnt[i];
        Q.push(make_pair(A[i]*((c+1)*(c+1)-c*c), i));
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
