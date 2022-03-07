#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(double x, int N, int K, vector<ll> &w, vector<ll> &p) {
    vector<double> v(N);
    for (int i = 0; i < N; i++) {
        v[i] = (p[i] - x) * w[i];
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    double sum = 0;
    for (int i = 0; i < K; i++) {
        sum += v[i];
    }

    return sum >= 0;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> w(N), p(N);
    for (int i = 0; i < N; i++) cin >> w[i] >> p[i];

    double left = -1.0;
    double right = 101.0;

    while (right - left > 1e-9) {
        double mid = (left + right) / 2.0;
        if (f(mid, N, K, w, p)) left = mid;
        else right = mid;
    }
    cout << fixed << setprecision(9) << left << endl;
}
