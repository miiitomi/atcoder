#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<int> X(N);
    vector<pair<int, int>> P(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        P[i] = make_pair(X[i], i);
    }
    sort(P.begin(), P.end());
    
    vector<ll> V(N);
    ll s = P[0].first;
    ll x = 0;
    for (int i = 0; i < N; i++) {
        x += abs(X[i]-s) + 1;
    }
    V[P[0].second] = x;

    for (int i = 1; i < N; i++) {
        ll diff = P[i].first - s;
        x += (2*i - N) * diff;
        V[P[i].second] = x;
        s = P[i].first;
    }
    for (int i = 0; i < N; i++) {
        if (i != N-1) cout << V[i] << " ";
        else cout << V[i] << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
