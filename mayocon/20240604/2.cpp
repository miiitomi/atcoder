// https://atcoder.jp/contests/abc222/tasks/abc222_c
#include <bits/stdc++.h>
using namespace std;

int win(char a, char b) {
    if (a == b) return 0;
    if (a == 'G' && b == 'C') return 1;
    if (a == 'C' && b == 'P') return 1;
    if (a == 'P' && b == 'G') return 1;
    return -1;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> A(2*N);
    for (int i = 0; i < 2*N; i++) cin >> A[i];

    vector<int> cnt(2*N, 0), v(2*N, 0);
    for (int i = 0; i < 2*N; i++) v[i] = i;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 2*N; j += 2) {
            int a = v[j], b = v[j+1];
            int res = win(A[a][i], A[b][i]);
            if (res == 1) cnt[a]++;
            else if (res == -1) cnt[b]++;
        }
        sort(v.begin(), v.end(), [&](int u, int v) {if (cnt[u] != cnt[v]) return cnt[u] > cnt[v]; else return u < v;});
    }

    for (int a : v) cout << 1+a << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
