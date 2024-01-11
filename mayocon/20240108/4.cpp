// https://atcoder.jp/contests/abc236/tasks/abc236_d
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N;
vector<vector<ll>> A;
ll ans = -1;

ll f(vector<int> &v) {
    ll tmp = 0;
    for (int i = 0; i < 2*N; i += 2) {
        tmp ^= A[v[i]][v[i+1]];
    }
    return tmp;
}

void dfs(vector<int> &v, ll S) {
    if ((int)v.size() == 2*N) {
        ans = max(ans, f(v));
        return;
    }
    bool see = false;
    for (ll i = 0; i < 2*N; i++) {
        if (S & (1LL << i)) continue;
        if (!see) {
            see = true;
            v.push_back(i);
            S += (1LL << i);
        } else {
            v.push_back(i);
            dfs(v, S + (1LL << i));
            v.pop_back();
        }
    }
    v.pop_back();
    return;
}

int main() {
    cin >> N;
    A.assign(2*N, vector<ll>(2*N, 0));
    for (int i = 0; i < 2*N; i++) {
        for (int j = i+1; j < 2*N; j++) {
            cin >> A[i][j];
            A[j][i] = A[i][j];
        }
    }

    vector<int> v;
    dfs(v, 0);
    cout << ans << endl;
}
