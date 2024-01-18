// https://atcoder.jp/contests/abc116/tasks/abc116_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int,int>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].second >> v[i].first;
        v[i].second--;
    }
    sort(v.begin(), v.end());

    vector<int> cnt(N, 0);
    ll x = 0;
    ll tmp = 0;
    priority_queue<int, vector<int>, greater<int>> Q;
    ll ans = -1;

    while (K--) {
        auto p = v.back();
        v.pop_back();
        tmp += p.first;
        cnt[p.second]++;
        if (cnt[p.second] == 1) x++;
        else Q.push(p.first);
    }

    ans = max(ans, tmp + x*x);
    while (!Q.empty() && !v.empty()) {
        auto p = v.back();
        v.pop_back();
        if (cnt[p.second] > 0) continue;
        cnt[p.second]++;
        x++;
        ll y = Q.top();
        Q.pop();
        tmp += p.first;
        tmp -= y;
        ans = max(ans, tmp + x*x);
    }

    cout << ans << endl;
}
