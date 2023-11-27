// https://atcoder.jp/contests/abc189/tasks/abc189_b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, X;
    cin >> N >> X;
    vector<ll> V(N), P(N);
    for (int i = 0; i < N; i++) cin >> V[i] >> P[i];

    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt += V[i] * P[i];
        if (cnt > X*100) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
