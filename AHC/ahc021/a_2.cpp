#include <bits/stdc++.h>
using namespace std;
const int N = 30;

int main() {
    vector<vector<int>> b(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> b[i][j];
        }
    }

    vector<pair<int, int>> V;

    for (int i = 29; i >= 1; i--) {
        for (int j = 0; j <= i; j++) {
            int x = i-1;

            int y0 = j-1;
            int y1 = j;

            if (j == 0) {
                if (b[x][y1] > b[i][j]) {
                    swap(b[x][y1], b[i][j]);
                    V.push_back(make_pair(x, y1));
                    V.push_back(make_pair(i, j));
                }
            } else if (j == i) {
                if (b[x][y0] > b[i][j]) {
                    swap(b[x][y0], b[i][j]);
                    V.push_back(make_pair(x, y0));
                    V.push_back(make_pair(i, j));
                }
            } else {
                if (b[x][y0] < b[x][y1]) swap(y0, y1);
                if (b[x][y0] > b[i][j]) {
                    swap(b[x][y0], b[i][j]);
                    V.push_back(make_pair(x, y0));
                    V.push_back(make_pair(i, j));
                }
            }

        }
    }

    cout << (int)V.size() / 2 << endl;
    for (int i = 0; i < (int)V.size(); i++) {
        if (i % 2 == 0) cout << V[i].first << " " << V[i].second << " ";
        else cout << V[i].first << " " << V[i].second << endl;
    }
}
