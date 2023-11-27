// https://atcoder.jp/contests/abc225/tasks/abc225_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<ll,ll> &p1, pair<ll,ll> &p2) {
    return (p1.second-1)*p2.first > (p2.second-1)*p1.first;
}

int main() {
    int N;
    cin >> N;
    vector<pair<ll,ll>> P(N);
    for (int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;
    sort(P.begin(), P.end(), cmp);

    int cnt = 1;
    ll x = P[0].first, y = P[0].second;
    for (int i = 1; i < N; i++) {
        pair<ll,ll> p = P[i];
        if ((y-1)*(p.first-1) >= x*p.second) {
            cnt++;
            x = p.first;
            y = p.second;
        }
    }

    cout << cnt << endl;
}
