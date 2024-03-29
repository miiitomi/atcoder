#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    ll W;
    cin >> W;
    vector<ll> v(N), w(N);
    for (int i = 0; i < N; i++) cin >> v[i] >> w[i];

    int N1 = N / 2;
    int N2 = N - N1;

    vector<pair<ll, ll>> P1, P2;
    for (ll b = 0; b < (1 << N1); b++) {
        pair<ll, ll> p = make_pair(0LL, 0LL);
        for (int i = 0; i < N1; i++) {
            if (b & (1 << i)) {
                p.first += w[i];
                p.second += v[i];
            }
        }
        P1.push_back(p);
    }
    for (ll b = 0; b < (1 << N2); b++) {
        pair<ll, ll> p = make_pair(0LL, 0LL);
        for (int i = 0; i < N2; i++) {
            if (b & (1 << i)) {
                p.first += w[N1+i];
                p.second += v[N1+i];
            }
        }
        P2.push_back(p);
    }

    sort(P2.begin(), P2.end());
    vector<pair<ll, ll>> V(1);
    V[0] = make_pair(0LL, 0LL);
    ll now = 0;
    for (int i = 0; i < (int)P2.size(); i++) {
        pair<ll, ll> p = P2[i];
        if (now == p.first) {
            V[(int)V.size()-1].second = max(V[(int)V.size()-1].second, p.second);
        } else {
            now = p.first;
            pair<ll, ll> q;
            q.first = now;
            q.second = max(V[(int)V.size()-1].second, p.second);
            V.push_back(q);
        }
    }

    ll ans = -1;
    for (auto p : P1) {
        pair<ll, ll> q = make_pair(W - p.first + 1, 0LL);
        auto iter = lower_bound(V.begin(), V.end(), q);
        if (iter == V.begin()) continue;
        iter--;
        ans = max(ans, p.second + iter->second);
    }
    cout << ans << endl;
}
