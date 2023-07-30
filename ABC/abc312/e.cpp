#include <bits/stdc++.h>
using namespace std;

vector<int> dx{1,-1,0,0,0,0};
vector<int> dy{0,0,1,-1,0,0};
vector<int> dz{0,0,0,0,1,-1};

int main() {
    int N;
    cin >> N;
    vector<vector<vector<int>>> V(100, vector<vector<int>>(100, vector<int>(100, -1)));
    for (int i = 0; i < N; i++) {
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int x = min(x1, x2); x < max(x1, x2); x++) {
            for (int y = min(y1, y2); y < max(y1, y2); y++) {
                for (int z = min(z1, z2); z < max(z1, z2); z++) {
                    V[x][y][z] = i;
                }
            }
        }
    }

    vector<set<int>> S(N);

    for (int x = 0; x < 100; x++) {
        for (int y = 0; y < 100; y++) {
            for (int z = 0; z < 100; z++) {
                if (V[x][y][z] == -1) continue;
                int i = V[x][y][z];
                for (int k = 0; k < 6; k++) {
                    int x1 = x + dx[k];
                    int y1 = y + dy[k];
                    int z1 = z + dz[k];
                    if (0 <= x1 && x1 < 100 && 0 <= y1 && y1 < 100 && 0 <= z1 && z1 < 100) {
                        int j = V[x1][y1][z1];
                        if (j != -1 && j != i) S[i].insert(j);
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << S[i].size() << endl;
    }
}
