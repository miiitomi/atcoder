#include <bits/stdc++.h>
using namespace std;

int D, num_block;
vector<string> f1, r1, f2, r2;
vector<vector<vector<int>>> b1, b2;

void input() {
    cin >> D;
    num_block = 0;

    f1.assign(D, "");
    r1.assign(D, "");
    f2.assign(D, "");
    r2.assign(D, "");
    for (int i = 0; i < D; i++) cin >> f1[i];
    for (int i = 0; i < D; i++) cin >> r1[i];
    for (int i = 0; i < D; i++) cin >> f2[i];
    for (int i = 0; i < D; i++) cin >> r2[i];

    b1.assign(D, vector<vector<int>>(D, vector<int>(D, 0)));
    b2.assign(D, vector<vector<int>>(D, vector<int>(D, 0)));
}

void output() {
    cout << num_block << endl;
    for (int x = 0; x < D; x++) {
        for (int y = 0; y < D; y++) {
            for (int z = 0; z < D; z++) {
                cout << b1[x][y][z];
                if (x == D-1 && y == D-1 && z == D-1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }
    }
    for (int x = 0; x < D; x++) {
        for (int y = 0; y < D; y++) {
            for (int z = 0; z < D; z++) {
                cout << b2[x][y][z];
                if (x == D-1 && y == D-1 && z == D-1) {
                    cout << endl;
                } else {
                    cout << " ";
                }
            }
        }
    }
}

void solve() {
    for (int x = 0; x < D; x++) {
        for (int y = 0; y < D; y++) {
            for (int z = 0; z < D; z++) {
                if (f1[z][x] == '1' && r1[z][y] == '1') {
                    num_block++;
                    b1[x][y][z] = num_block;
                }
            }
        }
    }

    for (int x = 0; x < D; x++) {
        for (int y = 0; y < D; y++) {
            for (int z = 0; z < D; z++) {
                if (f2[z][x] == '1' && r2[z][y] == '1') {
                    num_block++;
                    b2[x][y][z] = num_block;
                }
            }
        }
    }
}

int main() {
    input();
    solve();
    output();
}
