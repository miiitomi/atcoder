// https://atcoder.jp/contests/abc329/tasks/abc329_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> cnt(N+1, 0);
    int idx = 0, mx = 0;

    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        cnt[a]++;
        if (cnt[a] > mx || (cnt[a] == mx && idx > a)) {
            mx = cnt[a];
            idx = a;
        }
        cout << idx << endl;
    }
}
