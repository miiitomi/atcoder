#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<int> m(N);
    vector<vector<ll>> V(N);
    ll ans = 0;
    ll sum = 0;
    ll min_value = 1e+9 + 1;
    for (int i = 0; i < N; i++) {
        cin >> m[i];
        V[i].resize(m[i]);
        for (int j = 0; j < m[i]; j++) cin >> V[i][j];
        sort(V[i].begin(), V[i].end());
        ans += V[i][0];
        sum += V[i][1] - V[i][0];
        min_value = min(min_value, V[i][0]);
    }

    ll tmp = -1;
    for (int i = 0; i < N; i++) {
        ll new_tmp = ans + sum;
        new_tmp -= (V[i][1] - V[i][0]);
        new_tmp -= (V[i][0] - min_value);
        tmp = max(tmp, new_tmp);
    }

    cout << tmp << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
