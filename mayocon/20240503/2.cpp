// https://atcoder.jp/contests/abc145/tasks/abc145_c
#include <bits/stdc++.h>
using namespace std;

double dist(int x1, int y1, int x2, int y2) {return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+0.0);}

void solve() {
    int N;
    cin >> N;
    vector<int> x(N), y(N), v(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        v[i] = i;
    }
    double ans = 0;
    int cnt = 0;

    do {
        cnt++;
        for (int i = 0; i < N-1; i++) {
            ans += dist(x[v[i]], y[v[i]], x[v[i+1]], y[v[i+1]]);
        }
    } while (next_permutation(v.begin(), v.end()));

    ans /= cnt;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
