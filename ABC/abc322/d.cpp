#include <bits/stdc++.h>
using namespace std;

void kaiten(vector<string> &X) {
    vector<string> Y(4, "xxxx");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            Y[j][3-i] = X[i][j];
        }
    }
    X = Y;
}

bool g(vector<vector<string>> &P, vector<int> &I, vector<int> &J) {
    vector<vector<bool>> V(4, vector<bool>(4, false));
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (P[k][i][j] == '.') continue;
                if (!(0 <= I[k] + i && I[k] + i < 4 && 0 <= J[k] + j && J[k] + j < 4)) return false;
                if (V[I[k]+i][J[k]+j]) return false;
                V[I[k]+i][J[k]+j] = true;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!V[i][j]) return false;
        }
    }
    return true;
}


bool f(vector<vector<string>> &P) {
    vector<int> I(3), J(3);
    for (int i0 = -3; i0 <= 3; i0++) {
        for (int j0 = -3; j0 <= 3; j0++) {
            for (int i1 = -3; i1 <= 3; i1++) {
                for (int j1 = -3; j1 <= 3; j1++) {
                    for (int i2 = -3; i2 <= 3; i2++) {
                        for (int j2 = -3; j2 <= 3; j2++) {
                            I[0] = i0;
                            I[1] = i1;
                            I[2] = i2;
                            J[0] = j0;
                            J[1] = j1;
                            J[2] = j2;
                            if (g(P, I, J)) return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}


int main() {
    vector<vector<string>> P(3, vector<string>(4));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) cin >> P[i][j];
    }

    for (int t = 0; t < 4*4*4; t++) {
        bool ok = f(P);
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
        kaiten(P[2]);
        if (t % 4 == 3) kaiten(P[1]);
        if (t % 4*4 == 4*4-1) kaiten(P[0]);
    }

    cout << "No" << endl;
}
