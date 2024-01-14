// https://atcoder.jp/contests/abc325/tasks/abc325_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<pair<ll,ll>> V(N);
    for (int i = 0; i < N; i++) cin >> V[i].first >> V[i].second;
    sort(V.begin(), V.end());

    ll tmp = 1, idx = 0, ans=0;
    priority_queue<ll, vector<ll>, greater<ll>> Q;
    while (idx < N) {
        while (idx < N && V[idx].first == tmp) {
            Q.push(V[idx].first + V[idx].second);
            idx++;
        }

        ll T = 9e+18;
        if (idx < N) T = V[idx].first;
        while (!Q.empty() && tmp < T) {
            ll a = Q.top();
            Q.pop();
            if (tmp <= a) {
                ans++;
                tmp++;
            }
        }
        tmp = T;
    }

    cout << ans << endl;
}
