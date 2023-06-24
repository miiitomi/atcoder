#include <bits/stdc++.h>
using namespace std;

int main() {
    int h_a, w_a, h_b, w_b, h_x, w_x;
    cin >> h_a >> w_a;
    vector<string> A(h_a);
    for (int i = 0; i < h_a; i++) cin >> A[i];
    cin >> h_b >> w_b;
    vector<string> B(h_b);
    for (int i = 0; i < h_b; i++) cin >> B[i];
    cin >> h_x >> w_x;
    vector<string> X(h_x);
    for (int i = 0; i < h_x; i++) cin >> X[i];

    vector<string> Y;

    for (int i_a = -9; i_a <= 9; i_a++) {
        for (int j_a = -9; j_a <= 9; j_a++) {
            for (int i_b = -9; i_b <= 9; i_b++) {
                for (int j_b = -9; j_b <= 9; j_b++) {

                    Y = vector<string>(h_x, string(w_x, '.'));
                    bool is_possible = true;

                    for (int i = 0; i < h_a; i++) {
                        for (int j = 0; j < w_a; j++) {
                            if (A[i][j] == '#') {
                                if (0 <= i + i_a && i + i_a < h_x && 0 <= j + j_a && j + j_a < w_x) {
                                    Y[i + i_a][j + j_a] = '#';
                                } else {
                                    is_possible = false;
                                }
                            }
                        }
                    }

                    for (int i = 0; i < h_b; i++) {
                        for (int j = 0; j < w_b; j++) {
                            if (B[i][j] == '#') {
                                if (0 <= i + i_b && i + i_b < h_x && 0 <= j + j_b && j + j_b < w_x) {
                                    Y[i + i_b][j + j_b] = '#';
                                } else {
                                    is_possible = false;
                                }
                            }
                        }
                    }

                    if (is_possible && X == Y) {
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
