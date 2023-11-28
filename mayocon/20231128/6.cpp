// https://atcoder.jp/contests/abc294/tasks/abc294_f
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, K;
vector<ll> A, B, C, D;

bool is_greater_than_K(double p) {
    vector<double> v(M);
    for (int i = 0; i < M; i++) {
        v[i] = -(100.0 - p)*C[i] + p*D[i];
    }
    sort(v.begin(), v.end());
    ll cnt = 0;
    for (int i = 0; i < N; i++) {
        double l = (100.0 - p)*A[i] - p*B[i];
        cnt += distance(v.begin(), lower_bound(v.begin(), v.end(), l));
    }

    return cnt >= K;
}

int main() {
    cin >> N >> M >> K;
    A.resize(N);
    B.resize(N);
    C.resize(M);
    D.resize(M);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    for (int i = 0; i < M; i++) cin >> C[i] >> D[i];

    double left = 0.0, right = 100.0, mid;
    while (right - left > 1e-10) {
        mid = (right + left) / 2;
        if (is_greater_than_K(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    cout << fixed << setprecision(15) << right << endl;
}
