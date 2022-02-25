#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll INF = 10000000000000000LL;

int main() {
    ll N, W;
    cin >> N >> W;
    vector<ll> v(N), w(N);
    ll v_max = 0;
    ll w_max = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i] >> w[i];
        v_max = max(v_max, v[i]);
        w_max = max(w_max, w[i]);
    }

    if (N <= 30) {
        ll N1 = N / 2;
        ll N2 = N - N1;
        vector<pair<ll, ll>> V1, V2;

        for (ll i = 0; i < (1 << N1); i++) {
            pair<ll, ll> p;
            for (ll j = 0; j < N1; j++) {
                if (i & (1 << j)) {
                    p.first += w[j];
                    p.second += v[j];
                }
            }
            V1.push_back(p);
        }
    
        for (ll i = 0; i < (1 << N2); i++) {
            pair<ll, ll> p;
            for (ll j = 0; j < N2; j++) {
                if (i & (1 << j)) {
                    p.first += w[N1 + j];
                    p.second += v[N1 + j];
                }
            }
            V2.push_back(p);
        }

        sort(V1.begin(), V1.end());
        sort(V2.begin(), V2.end());

        vector<pair<ll, ll>> Q;
        ll w_now = 0;
        ll v_now = 0;
        for (auto p : V1) {
            if (w_now < p.first) {
                pair<ll, ll> q;
                q.first = w_now;
                q.second = v_now;
                Q.push_back(q);
                w_now = p.first;
            }
            if (v_now < p.second) v_now = p.second;
        }
        if (V1[(int)V1.size()-1].second == v_now) Q.push_back(V1[(int)V1.size()-1]);

        ll ans = 0;
        for (auto p : V2) {
            if (p.first > W) break;
            pair<ll, ll> q;
            q.first = W - p.first + 1;
            q.second = 0;
            auto iter = lower_bound(Q.begin(), Q.end(), q);
            iter--;
            ans = max(ans, p.second + iter->second);
        }

        cout << ans << endl;
        return 0;
    }

    if (w_max <= 1000) {
        ll w_sum = 0;
        for (int i = 0; i < N; i++) w_sum += w[i];
        W = min(W, w_sum);
        vector<vector<ll>> dp(N+1, vector<ll>(W+1, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= W; j++) {
                dp[i+1][j] = dp[i][j];
                if (j - w[i] >= 0) dp[i+1][j] = max(dp[i+1][j], dp[i][j-w[i]]+v[i]);
            }
        }
        cout << dp[N][W] << endl;
        return 0;
    }

    if (v_max <= 1000) {
        ll v_sum = 0;
        for (int i = 0; i < N; i++) v_sum += v[i];

        vector<vector<ll>> dp(N+1, vector<ll>(v_sum+1, INF));
        dp[0][0] = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= v_sum; j++) {
                dp[i+1][j] = dp[i][j];
                if (j - v[i] >= 0) dp[i+1][j] = min(dp[i+1][j], dp[i][j-v[i]] + w[i]);
            }
        }
        for (int i = v_sum; i >= 0; i--) {
            if (dp[N][i] <= W) {
                cout << i << endl;
                return 0;
            }
        }
    }
}
