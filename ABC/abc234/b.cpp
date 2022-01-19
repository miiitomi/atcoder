#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

    ll m = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            ll X = abs(x[i] - x[j]);
            ll Y = abs(y[i] - y[j]);
            m = max(m, X*X + Y*Y);
        }
    }
    double ans = sqrt((double)m);
    cout << fixed << setprecision(10) << ans << endl;
}
