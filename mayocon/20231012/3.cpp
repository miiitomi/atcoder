// https://atcoder.jp/contests/abc302/tasks/abc302_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M, D;
    cin >> N >> M >> D;
    vector<ll> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];
    sort(B.begin(), B.end());

    ll max_v = -1;
    for (ll a : A) {
        auto iter = lower_bound(B.begin(), B.end(), a + D + 1);
        if (iter == B.begin()) continue;
        iter--;
        if (abs(*iter - a) > D) continue;
        max_v = max(max_v, *iter + a);
    }

    cout << max_v << endl;
}
