#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<double> E(102, 0);
    int N;
    cin >> N;
    double ans = 0;
    while (N--) {
        int l, r;
        cin >> l >> r;
        double p = 1.0 / (r - l + 1);
        for (int x = l; x <= r; x++) {
            for (int y = x+1; y <= 100; y++) {
                ans += p*E[y];
            }
        }
        for (int x = l; x <= r; x++) E[x] += p;
    }
    cout << fixed << setprecision(15) << ans << endl;
}
