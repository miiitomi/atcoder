// https://atcoder.jp/contests/abc293/tasks/abc293_d
#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> G(2*N);
    vector<bool> reached(N, false);
    int circle = 0, path = 0;
    for (int j = 0; j < M; j++) {
        int a, c;
        char b, d;
        cin >> a >> b >> c >> d;
        a--;
        c--;

        if (a == c) {
            circle++;
            reached[a] = true;
            continue;
        }

        G[2*a + (int)(b == 'B')].push_back(2*c + (int)(d == 'B'));
        G[2*c + (int)(d == 'B')].push_back(2*a + (int)(b == 'B'));
    }

    for (int i = 0; i < N; i++) {
        if (reached[i]) continue;
        reached[i] = true;
        int l = 2*i, r = 2*i+1;
        bool is_cycle = false;
        while (!G[l].empty()) {
            l = G[l][0];
            if (l == r) {
                is_cycle = true;
                break;
            }
            if (l % 2) l--;
            else l++;
            reached[l/2] = true;
        }

        if (is_cycle) {
            circle++;
            continue;
        }

        while (!G[r].empty()) {
            r = G[r][0];
            if (r % 2) r--;
            else r++;
            reached[r/2] = true;
        }
        path++;
    }

    cout << circle << " " << path << endl;
}
