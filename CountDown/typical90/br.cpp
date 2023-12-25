#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    double x, y;
    if (N % 2 == 1) {
        x = X[N/2];
        y = Y[N/2];
    } else {
        x = (X[N/2 - 1] + X[N/2]) / 2.0;
        y = (Y[N/2 - 1] + Y[N/2]) / 2.0;
    }

    double ans = 0;
    for (int i = 0; i < N; i++) ans += abs(x - (double)X[i]) + abs(y - (double)Y[i]);

    cout << (ll)round(ans) << endl;
}
