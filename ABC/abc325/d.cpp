#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<pair<ll,ll>> V(N);
    for (int i = 0; i < N; i++) cin >> V[i].first >> V[i].second;
    sort(V.begin(), V.end());

    ll now = 0;
    priority_queue<ll, vector<ll>, greater<ll>> Q;
    ll ans = 0;

    for (int i = 0; i < N; i++) {
        while (!Q.empty() && now < V[i].first) {
            if (Q.top() < now) Q.pop();
            else {
                Q.pop();
                ans++;
                now++;
            }
        }

        now = V[i].first;
        Q.push(V[i].first + V[i].second);
    }

    while (!Q.empty()) {
        if (Q.top() < now) Q.pop();
        else {
            Q.pop();
            ans++;
            now++;
        }
    }

    cout << ans << endl;
}
