// https://atcoder.jp/contests/abc183/tasks/abc183_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> T(N, vector<ll>(N));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> T[i][j];

    vector<int> v;
    for (int i = 0; i < N; i++) v.push_back(i);

    int ans = 0;

    do {
        if (v[0] != 0) continue;
        ll tmp = 0;
        for (int i = 0; i < N; i++) {
            int j = (i + 1) % N;
            tmp += T[v[i]][v[j]];
            if (tmp == K) ans++;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
}
