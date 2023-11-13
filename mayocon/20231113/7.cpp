// https://atcoder.jp/contests/abc312/tasks/abc312_e
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<vector<int>>> V(101, vector<vector<int>>(101, vector<int>(101, -1)));
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x0, y0, z0, x1, y1, z1;
        cin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
        for (int x = x0; x < x1; x++) {
            for (int y = y0; y < y1; y++) {
                for (int z = z0; z < z1; z++) {
                    V[x][y][z] = i;
                }
            }
        }
    }

    vector<unordered_set<int>> S(N);
    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
            for (int z = 0; z <= 100; z++) {
                int s = x+1, t = y, u = z;
                if (0 <= s && s <= 100 && V[x][y][z] != -1 && V[s][t][u] != -1 && V[x][y][z] != V[s][t][u]) {
                    S[V[x][y][z]].insert(V[s][t][u]);
                    S[V[s][t][u]].insert(V[x][y][z]);
                }
                s = x-1;
                if (0 <= s && s <= 100 && V[x][y][z] != -1 && V[s][t][u] != -1 && V[x][y][z] != V[s][t][u]) {
                    S[V[x][y][z]].insert(V[s][t][u]);
                    S[V[s][t][u]].insert(V[x][y][z]);
                }
                s = x;
                t = y + 1;
                if (0 <= t && t <= 100 && V[x][y][z] != -1 && V[s][t][u] != -1 && V[x][y][z] != V[s][t][u]) {
                    S[V[x][y][z]].insert(V[s][t][u]);
                    S[V[s][t][u]].insert(V[x][y][z]);
                }
                t = y - 1;
                if (0 <= t && t <= 100 && V[x][y][z] != -1 && V[s][t][u] != -1 && V[x][y][z] != V[s][t][u]) {
                    S[V[x][y][z]].insert(V[s][t][u]);
                    S[V[s][t][u]].insert(V[x][y][z]);
                }
                t = y;
                u = z+1;
                if (0 <= u && u <= 100 && V[x][y][z] != -1 && V[s][t][u] != -1 && V[x][y][z] != V[s][t][u]) {
                    S[V[x][y][z]].insert(V[s][t][u]);
                    S[V[s][t][u]].insert(V[x][y][z]);
                }
                u = z-1;
                if (0 <= u && u <= 100 && V[x][y][z] != -1 && V[s][t][u] != -1 && V[x][y][z] != V[s][t][u]) {
                    S[V[x][y][z]].insert(V[s][t][u]);
                    S[V[s][t][u]].insert(V[x][y][z]);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << S[i].size() << endl;
    }
}
