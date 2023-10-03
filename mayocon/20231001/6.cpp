// https://atcoder.jp/contests/abc268/tasks/abc268_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<int> Q(N);
    for (int i = 0; i < N; i++) {
        int p;
        cin >> p;
        Q[p] = i;
    }

    vector<ll> V(2*N, 0);
    for (int i = 0; i < N; i++) {
        int k = (i + N - Q[i]) % N;
        V[k+1] += 1;
        V[k+(N/2)+1] += -1;
        V[k+((N+1)/2)+1] += -1;
        if (k != N-1) V[k+N+1] += 1;
    }

    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < 2*N-1; i++) V[i+1] = V[i+1] + V[i];
    }

    ll ans = 1e+18;
    for (int i = 0; i < N; i++) ans = min(ans, V[i] + V[i+N]);

    cout << ans << endl;
}
