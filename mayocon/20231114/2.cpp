// https://atcoder.jp/contests/abc309/tasks/abc309_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<ll, ll>> V(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> V[i].first >> V[i].second;
        sum += V[i].second;
    }
    sort(V.begin(), V.end());
    ll d = 1;
    if (sum <= K) {
        cout << d << endl;
        return 0;
    }

    for (auto v : V) {
        d = v.first + 1;
        sum -= v.second;
        if (sum <= K) {
            cout << d << endl;
            return 0;
        }
    }
}
