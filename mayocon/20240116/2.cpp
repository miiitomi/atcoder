// https://atcoder.jp/contests/abc145/tasks/abc145_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i = 0; i < N; i++) cin >> x[i] >> y[i];
    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i;
    int cnt = 0;
    double ans = 0;

    do {
        double tmp = 0;
        for (int k = 0; k < N-1; k++) {
            double sx = x[v[k]], sy = y[v[k]], tx = x[v[k+1]], ty = y[v[k+1]];
            tmp += sqrt((sx-tx)*(sx-tx) + (sy - ty)*(sy - ty));
        }
        ans += tmp;
        cnt++;
    } while (next_permutation(v.begin(), v.end()));

    cout << fixed << setprecision(15) << ans / cnt << endl;
}
