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

    bool update = true;
    
    while (update) {
        update = false;
        for (int i = 29; i >= 1; i--) {
            for (int j = 0; j <= i; j++) {
                int x = i-1;
                int y = j-1;

                if (j != 0) {
                    if (b[x][y] > b[i][j]) {
                        swap(b[x][y], b[i][j]);
                        V.push_back(make_pair(x, y));
                        V.push_back(make_pair(i, j));
                        update = true;
                    }
                }

                y++;
                if (j != i) {
                    if (b[x][y] > b[i][j]) {
                        swap(b[x][y], b[i][j]);
                        V.push_back(make_pair(x, y));
                        V.push_back(make_pair(i, j));
                        update = true;
                    }
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
