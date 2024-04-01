// https://atcoder.jp/contests/abc294/tasks/abc294_f
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, M, K;
vector<ll> A, B, C, D;

bool ok(double x) {
    vector<double> v(M);
    for (int i = 0; i < M; i++) {
        v[i] = (x - 100.0) * C[i] + x * D[i];
    }
    sort(v.begin(), v.end());
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        double y = (100.0 - x) * A[i] - x * B[i];
        cnt += (int)distance(v.begin(), lower_bound(v.begin(), v.end(), y));
    }
    return cnt >= K;
}

void solve() {
    cin >> N >> M >> K;
    A.resize(N);
    B.resize(N);
    C.resize(M);
    D.resize(M);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    for (int i = 0; i < M; i++) cin >> C[i] >> D[i];

    double left = 0, right = 100;
    for (int t = 0; t < 100; t++) {
        double x = (right + left) / 2.0;
        if (ok(x)) left = x;
        else right = x;
    }

    cout << left << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
