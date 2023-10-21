// https://atcoder.jp/contests/abc126/tasks/abc126_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<double> P(max(N, K)+1, 0);
    for (int i = (int)P.size()-1; i >= 1; i--) {
        if (i >= K) P[i] = 1.0;
        else {
            if (i*2 >= K) P[i] = 0.5;
            else P[i] = 0.5 * P[2*i];
        }
    }

    double ans = 0;
    for (int i = 1; i <= N; i++) ans += P[i];
    ans /= N;

    cout << fixed << setprecision(15) << ans << endl;
}
