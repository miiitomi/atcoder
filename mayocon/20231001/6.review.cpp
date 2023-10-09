// https://atcoder.jp/contests/abc268/tasks/abc268_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<ll> Q(N);
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        Q[p] = i;
    }

    vector<ll> X(2*N+1, 0);
    for (int i = 0; i < N; i++) {
        int q = (i - Q[i] + N) % N;
        X[q+1]++;
        X[q+(N+2)/2]--;
        X[q+(N+3)/2]--;
        X[q+N+1]++;
    }

    for (int k = 0; k < 2; k++) {
        for (int i = 1; i <= 2*N; i++) X[i] += X[i-1];
    }

    ll ans = 2e+18;
    for (int i = 0; i < N; i++) ans = min(ans, X[i] + X[i+N]);
    cout << ans << endl;
}
