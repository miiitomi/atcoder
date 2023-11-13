// https://atcoder.jp/contests/abc322/tasks/abc322_d
#include <bits/stdc++.h>
using namespace std;

void rmv(vector<string> &S) {
    bool done = false;
    while (!done) {
        done = true;
        bool rem = true;
        for (int i = 0; i < (int)S[0].size(); i++) {
            if (S[0][i] == '#') rem = false;
        }
        if (rem) {
            for (int i = 0; i < S.size()-1; i++) {
                S[i] = S[i+1];
            }
            S.pop_back();
            done = false;
        }
    }

    done = false;
    while (!done) {
        done = true;
        bool rem = true;
        for (int j = 0; j < (int)S[0].size(); j++) {
            if (S[(int)S.size()-1][j] == '#') rem = false;
        }
        if (rem) {
            S.pop_back();
            done = false;
        }
    }

    done = false;
    while (!done) {
        done = true;
        bool rem = true;
        for (int i = 0; i < (int)S.size(); i++) {
            if (S[i][0] == '#') rem = false;
        }
        if (rem) {
            done = false;
            for (int i = 0; i < (int)S.size(); i++) {
                for (int j = 0; j < (int)S[i].size()-1; j++) S[i][j] = S[i][j+1];
                S[i].pop_back();
            }
        }
    }

    done = false;
    while (!done) {
        done = true;
        bool rem = true;
        for (int i = 0; i < (int)S.size(); i++) {
            if (S[i][(int)S[i].size()-1] == '#') rem = false;
        }
        if (rem) {
            done = false;
            for (int i = 0; i < (int)S.size(); i++) S[i].pop_back();
        }
    }
}

void kaiten(vector<string> &S) {
    vector<string> T((int)S[0].size(), string(S.size(), '#'));
    for (int i = 0; i < (int)S.size(); i++) {
        for (int j = 0; j < (int)S[0].size(); j++) {
            T[j][(int)S.size()-1-i] = S[i][j];
        }
    }
    S = T;
}

bool is_ok(vector<vector<string>> S) {
    for (int i0 = 0; i0 + S[0].size() <= 4; i0++) {
        for (int j0 = 0; j0 + S[0][0].size() <= 4; j0++) {
            for (int i1 = 0; i1 + S[1].size() <= 4; i1++) {
                for (int j1 = 0; j1 + S[1][0].size() <= 4; j1++) {
                    for (int i2 = 0; i2 + S[2].size() <= 4; i2++) {
                        for (int j2 = 0; j2 + S[2][0].size() <= 4; j2++) {
                            vector<int> i{i0, i1, i2}, j{j0, j1, j2};
                            bool ok = true;
                            vector<string> P(4, string(4, '.'));
                            for (int k = 0; k < 3; k++) {
                                for (int x = 0; x < (int)S[k].size(); x++) {
                                    for (int y = 0; y < (int)S[k][0].size(); y++) {
                                        if (S[k][x][y] == '.') continue;
                                        else if (P[i[k] + x][j[k] + y] == '#') {
                                            ok = false;
                                            break;
                                        } else {
                                            P[i[k] + x][j[k] + y] = '#';
                                        }
                                    }
                                }
                            }
                            if (ok) return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    vector<string> S(4, string(4, '.')), T(4, string(4, '.')), U(4, string(4, '.'));
    for (int i = 0; i < 4; i++) cin >> S[i];
    for (int i = 0; i < 4; i++) cin >> T[i];
    for (int i = 0; i < 4; i++) cin >> U[i];

    int cnt = 0;
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cnt += (S[i][j] == '#');
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cnt += (T[i][j] == '#');
    for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) cnt += (U[i][j] == '#');
    if (cnt != 16) {
        cout << "No" << endl;
        return 0;
    }

    rmv(S);
    rmv(T);
    rmv(U);

    for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
            vector<vector<string>> V{S, T, U};
            if (is_ok(V)) {
                cout << "Yes" << endl;
                return 0;
            }
            kaiten(U);
        }
        kaiten(T);
    }

    cout << "No" << endl;
}
