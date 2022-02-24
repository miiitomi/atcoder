#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    N++;
    vector<int> P(N);
    for (int i = 0; i < N-1; i++) cin >> P[i];
    P[N-1] = 0;
    vector<int> Q;
    Q.reserve((N * (N+1)) / 2);
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            Q.push_back(P[i] + P[j]);
        }
    }
    sort(Q.begin(), Q.end());

    int ans = 0;
    for (int i = 0; i < (int)Q.size(); i++) {
        int q = Q[i];
        if (q > M) continue;
        auto iter = lower_bound(Q.begin(), Q.end(), M - q + 1);
        if (iter == Q.begin()) continue;
        iter--;
        ans = max(ans, q + *iter);
    }

    cout << ans << endl;
}
