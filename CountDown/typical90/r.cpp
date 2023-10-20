#include <bits/stdc++.h>
using namespace std;

int T, L, X, Y, Q;

void solve() {
    int E;
    cin >> E;

    double theta = (2.0 * (E % T) / T - 0.5) * M_PI;
    double r = L / 2.0;
    double y = - r * cos(theta);
    double z = r + r * sin(theta);
    double w = pow(X*X + pow(Y-y, 2.0), 0.5);
    cout << atan2(z, w) * 180.0 / M_PI << endl;
}

int main() {
    cin >> T >> L >> X >> Y >> Q;
    cout << fixed << setprecision(15);
    for (int i = 0; i < Q; i++) solve();
}
