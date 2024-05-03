// https://atcoder.jp/contests/abc189/tasks/abc189_f
#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<int> A;
vector<bool> is_bad;

double f(double m) {
    vector<double> dp(N+1, 0);
    queue<double> Q;
    double sum = 0;
    for (int l = 0; l < M; l++) Q.push(0);
    for (int i = N-1; i >= 0; i--) {
        if (is_bad[i]) {
            dp[i] = m;
            sum -= Q.front();
            Q.pop();
            sum += dp[i];
            Q.push(dp[i]);
        } else {
            dp[i] = 1.0 + (sum) / M;
            sum -= Q.front();
            Q.pop();
            sum += dp[i];
            Q.push(dp[i]);
        }
    }
    return dp[0];
}

void solve() {
    cin >> N >> M >> K;
    A.resize(K);
    is_bad.assign(N+1, false);
    for (int k = 0; k < K; k++) {
        cin >> A[k];
        is_bad[A[k]] = true;
    }

    int cnt = 0, tmp = 0;
    for (int i = 0; i <= N; i++) {
        if (is_bad[i]) tmp++;
        else {
            cnt = max(cnt, tmp);
            tmp = 0;
        }
    }
    if (cnt >= M) {
        cout << -1 << "\n";
        return;
    }

    double l = 0, r = 1e+18;
    for (int s = 0; s < 300; s++) {
        double m = (l + r) / 2;
        double res = f(m);
        if (res < m) r = m;
        else if (res > m) l = m;
        else {
            r = m;
            break;
        }
    }
    cout << r << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
