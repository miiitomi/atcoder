#include <bits/stdc++.h>
using namespace std;

int D, num_block;
vector<string> f1, r1, f2, r2;
vector<vector<vector<int>>> b1, b2;

vector<int> dx{1, -1, 0, 0, 0, 0};
vector<int> dy{0, 0, 1, -1, 0, 0};
vector<int> dz{0, 0, 0, 0, 1, -1};

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
    int num_block_1 = 0;
    vector<vector<bool>> done_f(D, vector<bool>(D, false)), done_r(D, vector<bool>(D, false));

    for (int x = 0; x < D; x++) {
        for (int y = 0; y < D; y++) {
            for (int z = 0; z < D; z++) {
                if (f1[z][x] == '1' && r1[z][y] == '1' && (!done_f[z][x] || !done_r[z][y])) {
                    num_block_1++;
                    b1[x][y][z] = num_block_1;
                    done_f[z][x] = true;
                    done_r[z][y] = true;
                }
            }
        }
    }

    int num_block_2 = 0;
    done_f.assign(D, vector<bool>(D, false));
    done_r.assign(D, vector<bool>(D, false));
    for (int x = 0; x < D; x++) {
        for (int y = 0; y < D; y++) {
            for (int z = 0; z < D; z++) {
                if (f2[z][x] == '1' && r2[z][y] == '1' && (!done_f[z][x] || !done_r[z][y])) {
                    num_block_2++;
                    b2[x][y][z] = num_block_2;
                    done_f[z][x] = true;
                    done_r[z][y] = true;
                }
            }
        }
    }

    vector<int> pair_no_1(num_block_1+1, 0);
    vector<int> pair_no_2(num_block_2+1, 0);
    int num_pair_1 = 0;
    int num_pair_2 = 0;
    for (int x = 0; x < D; x++) {
        for (int y = 0; y < D; y++) {
            for (int z = 0; z < D; z++) {
                if (b1[x][y][z] != 0 && pair_no_1[b1[x][y][z]] == 0) {
                    for (int k = 0; k < 6; k++) {
                        int x_ = x + dx[k];
                        int y_ = y + dy[k];
                        int z_ = z + dz[k];
                        if (0 <= x_ && x_ < D && 0 <= y_ && y_ < D && 0 <= z_ && z_ < D) {
                            if (b1[x_][y_][z_] != 0 && pair_no_1[b1[x_][y_][z_]] == 0) {
                                num_pair_1++;
                                pair_no_1[b1[x][y][z]] = num_pair_1;
                                pair_no_1[b1[x_][y_][z_]] = num_pair_1;
                                break;
                            }
                        }
                    }
                }

                if (b2[x][y][z] != 0 && pair_no_2[b2[x][y][z]] == 0) {
                    for (int k = 0; k < 6; k++) {
                        int x_ = x + dx[k];
                        int y_ = y + dy[k];
                        int z_ = z + dz[k];
                        if (0 <= x_ && x_ < D && 0 <= y_ && y_ < D && 0 <= z_ && z_ < D) {
                            if (b2[x_][y_][z_] != 0 && pair_no_2[b2[x_][y_][z_]] == 0) {
                                num_pair_2++;
                                pair_no_2[b2[x][y][z]] = num_pair_2;
                                pair_no_2[b2[x_][y_][z_]] = num_pair_2;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    int num_pair_block = max(num_pair_1, num_pair_2);
    int single_block_1 = 0;
    int single_block_2 = 0;
    for (int x = 0; x < D; x++) {
        for (int y = 0; y < D; y++) {
            for (int z = 0; z < D; z++) {
                if (b1[x][y][z] != 0) {
                    if (pair_no_1[b1[x][y][z]] != 0) {
                        b1[x][y][z] = pair_no_1[b1[x][y][z]];
                    } else {
                        single_block_1++;
                        b1[x][y][z] = num_pair_block + single_block_1;
                    }
                }

                if (b2[x][y][z] != 0) {
                    if (pair_no_2[b2[x][y][z]] != 0) {
                        b2[x][y][z] = pair_no_2[b2[x][y][z]];
                    } else {
                        single_block_2++;
                        b2[x][y][z] = num_pair_block + single_block_2;
                    }
                }
            }
        }
    }
    num_block = num_pair_block + max(single_block_1, single_block_2);
}

int main() {
    input();
    solve();
    output();
}
