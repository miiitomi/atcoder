#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    for (int i = 0; i < N; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        Q.push(p);
    }

    ll ans = 0;
    while (K > 0) {
        pair<ll, ll> p = Q.top();
        Q.pop();
        ans += p.first;
        p.first += p.second;
        Q.push(p);
        K--;
    }
    cout << ans << endl;
}
