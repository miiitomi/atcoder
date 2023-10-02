// https://atcoder.jp/contests/abc290/tasks/abc290_e
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<vector<ll>> V(N);
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        a--;
        V[a].push_back(i);
    }

    ll m = 0;
    for (int a = 0; a < N; a++) {
        if (V[a].size() <= 1) continue;
        int i = 0, j = V[a].size()-1;
        while (i != j) {
            ll x = V[a][i], y = V[a][j];
            m += (1 + min(x, N-1-y)) * (j-i);
            if (x == min(x, N-1-y)) i++;
            else j--;
        }
    }

    ll ans = 0 - m;
    for (int k = 1; k <= N-1; k++) ans += ((k+1) / 2) * (N-k);
    cout << ans << endl;
}
