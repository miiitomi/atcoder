// https://atcoder.jp/contests/abc245/tasks/abc245_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> X(N), Y(M);
    for (int i = 0; i < N; i++) cin >> X[i].first;
    for (int i = 0; i < N; i++) cin >> X[i].second;
    for (int j = 0; j < M; j++) cin >> Y[j].first;
    for (int j = 0; j < M; j++) cin >> Y[j].second;
    sort(X.begin(), X.end());
    reverse(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    multiset<ll> Q;
    for (auto &y : Y) {
        while (!X.empty() && X.back().first <= y.first) {
            ll x = X.back().second;
            X.pop_back();
            Q.insert(x);
        }
        if (Q.empty()) continue;
        auto iter = Q.lower_bound(y.second+1);
        if (iter != Q.begin()) {
            iter--;
            Q.erase(iter);
        }
    }

    if (X.empty() && Q.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;
}
