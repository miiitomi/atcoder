// https://atcoder.jp/contests/abc109/tasks/abc109_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W, 0));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> A[i][j];

    vector<pair<int,int>> a, b;
    for (int i = 0; i < H; i++) {
        deque<int> D;
        for (int j = 0; j < W; j++) if (A[i][j] & 1) D.push_back(j);

        while (D.size() >= 2) {
            int s = D.front();
            D.pop_front();
            int t = D.front();
            D.pop_front();
            while (s < t) {
                a.push_back(make_pair(i+1, s+1));
                b.push_back(make_pair(i+1, s+2));
                s++;
            }
        }

        if (!D.empty() && i < H-1) {
            int s = D.front();
            D.pop_front();
            int t = W-1;
            while (s < t) {
                a.push_back(make_pair(i+1, s+1));
                b.push_back(make_pair(i+1, s+2));
                s++;
            }
            a.push_back(make_pair(i+1, s+1));
            b.push_back(make_pair(i+2, s+1));
            A[i+1][W-1]++;
        }
    }

    cout << a.size() << "\n";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i].first << " " << a[i].second << " " << b[i].first << " " << b[i].second << "\n";
    }
}
