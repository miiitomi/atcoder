// https://atcoder.jp/contests/abc289/tasks/abc289_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a(M);
    for (int i = 0; i < M; i++) {
        int c;
        cin >> c;
        while (c--) {
            int x;
            cin >> x;
            x--;
            a[i].push_back(x);
        }
    }

    int cnt = 0;
    for (int s = 1; s < (1 << M); s++) {
        set<int> S;
        for (int k = 0; k < M; k++) {
            if (!(s & (1 << k))) continue;
            for (int y : a[k]) S.insert(y);
        }
        if (S.size() == N) cnt++;
    }

    cout << cnt << endl;
}
