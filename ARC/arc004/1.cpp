#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];

    double ans = 0;
    for (int i = 0; i < N-1; i++) {
        for (int j = i+1; j < N; j++) {
            double dx = x[i] - x[j];
            double dy = y[i] - y[j];
            double d = sqrt((dx * dx) + (dy * dy));
            ans = max(ans, d);
        }
    }
    cout << fixed << setprecision(6) << ans << endl;
}
