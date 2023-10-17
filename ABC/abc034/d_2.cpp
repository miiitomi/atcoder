#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> w, p;
vector<double> c;

bool is_ok(double x) {
    vector<double> v(N);
    for (int i = 0; i < N; i++) {
        v[i] = c[i] - w[i] * x;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    double tmp = 0;
    for (int k = 0; k < K; k++) tmp += v[k];

    return tmp >= 0.0;
}

int main() {
    cin >> N >> K;
    w.resize(N);
    p.resize(N);
    c.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> p[i];
        c[i] = w[i] * (p[i] / 100.0);
    }

    double left = -0.1;
    double right = 100.1;

    while (right - left > 1e-12) {
        double x = (right + left) / 2.0;
        if (is_ok(x)) left = x;
        else right = x;
    }

    cout << fixed << setprecision(9) << 100.0 * left << endl;
}
