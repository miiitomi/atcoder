// https://atcoder.jp/contests/abc189/tasks/abc189_f
#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<int> A;
vector<bool> is_trap;

double f(double x) {
    vector<double> dp(N);
    queue<double> Q;
    double tmp = 0;
    for (int m = 0; m < M; m++) Q.push(0);
    for (int i = N-1; i >= 0; i--) {
        if (is_trap[i]) dp[i] = x;
        else dp[i] = 1.0 + (tmp / M);
        tmp -= Q.front();
        Q.pop();
        Q.push(dp[i]);
        tmp += dp[i];
    }
    return abs(x-dp[0]);
}

int main() {
    cin >> N >> M >> K;
    A.resize(K);
    is_trap.assign(N, false);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
        is_trap[A[i]] = true;
    }

    vector<bool> can_reach(N+1, false);
    can_reach[0] = true;
    queue<int> Q;
    Q.push(0);
    for (int i = 1; i <= N; i++) {
        while (!Q.empty() && abs(Q.front() - i) > M) Q.pop();
        can_reach[i] = !Q.empty() && !is_trap[i];
        if (can_reach[i]) Q.push(i);
    }

    if (!can_reach[N]) {
        cout << -1 << endl;
        return 0;
    }


    double left = 0.0, right = 1e+18;
    while (right - left > 1e-5) {
        double s = left + (right - left)/3, t = left + 2*(right - left)/3;
        double a = f(s), b = f(t);
        if (a >= b) left = s;
        else right = t;
    }

    cout << fixed << setprecision(15) << (right + left) / 2 << endl;
}
