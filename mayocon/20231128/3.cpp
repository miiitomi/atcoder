// https://atcoder.jp/contests/abc187/tasks/abc187_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<pair<ll, ll>> X(N);
    ll tmp = 0;
    for (int i = 0; i < N; i++) {
        cin >> X[i].first >> X[i].second;
        tmp -= X[i].first;
    }
    sort(X.begin(), X.end(), [](auto &p1, auto &p2) {return 2*p1.first + p1.second > 2*p2.first + p2.second;});

    ll cnt = 0;
    for (auto &p : X) {
        cnt++;
        tmp += 2*p.first + p.second;
        if (tmp > 0) break;
    }

    cout << cnt << endl;
}
