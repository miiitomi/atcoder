// https://atcoder.jp/contests/abc127/tasks/abc127_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> S(N+1, 0);
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        S[l]++;
        S[r]--;
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == M) cnt++;
        S[i+1] += S[i];
    }

    cout << cnt << endl;
}
