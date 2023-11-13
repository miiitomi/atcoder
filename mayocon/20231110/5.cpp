// https://atcoder.jp/contests/abc312/tasks/abc312_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> v0, v1, w;
    for (int i = 0; i < N; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 0) v0.push_back(x);
        else if (t == 1) v1.push_back(x);
        else w.push_back(x);
    }
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());
    sort(w.begin(), w.end());

    priority_queue<ll, vector<ll>, greater<ll>> Q;
    int cnt = 0;
    ll ans = 0;

    for (int k = 0; k < M && !v0.empty(); k++) {
        int x = v0.back();
        v0.pop_back();
        Q.push(x);
        cnt++;
        ans += x;
    }

    while (!w.empty()) {
        ll tmp = ans;
        int y = w.back();
        w.pop_back();
        cnt++;
        if (cnt > M && !Q.empty()) {
            ll x = Q.top();
            Q.pop();
            tmp -= x;
            cnt--;
        } else if (cnt > M && Q.empty()) break;

        while (y > 0 && cnt < M && !v1.empty()) {
            ll x = v1.back();
            v1.pop_back();
            cnt++;
            y--;
            Q.push(x);
            tmp += x;
        }

        while (y > 0 && !v1.empty() && !Q.empty() && Q.top() < v1.back()) {
            y--;
            ll x = Q.top();
            Q.pop();
            tmp -= x;
            x = v1.back();
            v1.pop_back();
            tmp += x;
        }

        ans = max(ans, tmp);
    }

    cout << ans << endl;
}
