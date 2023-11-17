#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll INF = (ll)3e+18;
ll dist(ll x1, ll y1, ll x2, ll y2) {return (x1-x2)*(x1-x2) + (y1 - y2)*(y1 - y2);}

int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> X(N), Y(N);
    for (ll i = 0; i < N; i++) cin >> X[i] >> Y[i];

    vector<ll> d((1 << N), 0);
    for (int s = 0; s < (1 << N); s++) {
        vector<int> v;
        for (int i = 0; i < N; i++) if (s & (1 << i)) v.push_back(i);
        for (int i = 0; i < (int)v.size(); i++) {
            for (int j = i + 1; j < (int)v.size(); j++) {
                d[s] = max(d[s], dist(X[v[i]], Y[v[i]], X[v[j]], Y[v[j]]));
            }
        }
    }

    vector<vector<ll>> dp((1 << N), vector<ll>(K+1, INF));
    for (int s = 0; s < (1 << N); s++) {
        dp[s][1] = d[s];
        vector<int> v;
        for (int i = 0; i < N; i++) if (s & (1 << i)) v.push_back(i);
        int L = v.size();
        for (int t = 0; t < (1 << L); t++) {
            int s_ = 0;
            for (int j = 0; j < L; j++) if (t & (1 << j)) s_ += (1 << v[j]);
            for (int cnt = 2; cnt <= K; cnt++) dp[s][cnt] = min(dp[s][cnt], max(dp[s_][cnt-1], d[s - s_]));
        }
    }

    int s = (1 << N) - 1;
    cout << dp[s][K] << endl;
}
