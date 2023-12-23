// https://atcoder.jp/contests/abc183/tasks/abc183_c
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, K;
    cin >> N >> K;
    vector<vector<ll>> T(N, vector<ll>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> T[i][j];
    }

    vector<int> v(N-1);
    for (int i = 1; i < N; i++) v[i-1] = i;
    ll cnt = 0;
    do {
        int tmp = 0;
        ll time = 0;
        for (int nv : v) {
            time += T[tmp][nv];
            tmp = nv;
        }
        time += T[tmp][0];
        if (time == K) cnt++;
    } while (next_permutation(v.begin(), v.end()));

    cout << cnt << endl;
}
