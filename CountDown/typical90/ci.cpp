#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, P, K;
vector<vector<ll>> A;

int f(ll X) {
    vector<vector<ll>> dp(N, vector<ll>(N, 1e+18));
    for (int s = 0; s < N; s++) {
        dp[s][s] = 0;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
        Q.push(make_pair(0, s));
        while (!Q.empty()) {
            auto p = Q.top();
            Q.pop();
            int v = p.second;
            ll dist = p.first;
            if (dp[s][v] != dist) continue;
            for (int w = 0; w < N; w++) {
                ll c = X;
                if (A[v][w] > -1) c = A[v][w];
                if (dp[s][w] > dp[s][v] + c) {
                    dp[s][w] = dp[s][v] + c;
                    Q.push(make_pair(dp[s][w], w));
                } 
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            if (dp[i][j] <= P) cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> N >> P >> K;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ll a;
            cin >> a;
            A[i].push_back(a);
        }
    }

    ll s = f((ll)1e+10), t = f(1);

    if (s == K) {
        cout << "Infinity" << endl;
        return 0;
    } else if (t < K || s > K) {
        cout << 0 << endl;
        return 0;
    }

    ll l1 = 1, r1 = 1e+10;
    while (r1 - l1 > 1) {
        ll m = (r1 + l1) / 2;
        if (f(m) >= K) l1 = m;
        else r1 = m;
    }

    ll l2 = 0, r2 = 1e+10;
    while (r2 - l2 > 1) {
        ll m = (r2 + l2) / 2;
        if (f(m) <= K) r2 = m;
        else l2 = m;
    }

    cout << l1 - r2 + 1 << endl;
}
