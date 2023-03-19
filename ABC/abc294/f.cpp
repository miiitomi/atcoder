#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M, K;
vector<int> A, B, C, D;

ll f(double p) {
    vector<double> V(M);
    for (int i = 0; i < M; i++) {
        double c = C[i];
        double d = D[i];
        V[i] = d - c*(100.0 - p)/p;
    }
    sort(V.begin(), V.end());

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        double a = A[i];
        double b = B[i];
        double s = -b + a*(100.0-p)/p;
        auto iter = upper_bound(V.begin(), V.end(), s);
        ans += (ll)distance(V.begin(), iter);
    }

    return ans;
}

int main() {
    cin >> N >> M >> K;
    A.assign(N, 0);
    B.assign(N, 0);
    C.assign(M, 0);
    D.assign(M, 0);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    for (int j = 0; j < M; j++) cin >> C[j] >> D[j];

    double left = 0.0;
    double right = 100.0;
    double mid;
    while (right - left > 1e-13) {
        mid = (left + right) / 2.0;
        ll ans = f(mid);
        if (ans >= K) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << fixed << setprecision(13) << mid << endl;
}
