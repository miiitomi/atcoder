// https://atcoder.jp/contests/abc151/tasks/abc151_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int pena = 0;
    vector<int> cnt(N, 0);
    for (int i = 0; i < M; i++) {
        int p;
        cin >> p;
        string s;
        cin >> s;
        p--;
        if (cnt[p] < 0) continue;
        if (s == "AC") {
            pena += cnt[p];
            cnt[p] = -1;
        } else {
            cnt[p]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) if (cnt[i] < 0) ans++;
    cout << ans << " " << pena << endl;
}
