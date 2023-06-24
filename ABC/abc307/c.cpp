#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;

void h_w_s_erase(int &h, int &w, vector<string> &S) {
    bool update = true;
    while (update) {
        update = false;
        
        bool can_erase = true;
        for (int j = 0; j < w; j++) {
            if (S[0][j] == '#') {
                can_erase = false;
                break;
            }
        }
        if (can_erase) {
            S.erase(S.begin());
            h--;
            update = true;
        }

        can_erase = true;
        for (int j = 0; j < w; j++) {
            if (S[h-1][j] == '#') {
                can_erase = false;
                break;
            }
        }
        if (can_erase) {
            S.pop_back();
            h--;
            update = true;
        }

        can_erase = true;
        for (int i = 0; i < h; i++) {
            if (S[i][0] == '#') {
                can_erase = false;
                break;
            }
        }
        if (can_erase) {
            for (int i = 0; i < h; i++) {
                S[i].erase(S[i].begin());
            }
            w--;
            update = true;
        }

        can_erase = true;
        for (int i = 0; i < h; i++) {
            if (S[i][w-1] == '#') {
                can_erase = false;
                break;
            }
        }
        if (can_erase) {
            for (int i = 0; i < h; i++) {
                S[i].pop_back();
            }
            w--;
            update = true;
        }
    }
}


int main() {
    int H_a, W_a, H_b, W_b, H_x, W_x;
    cin >> H_a >> W_a;
    vector<string> A(H_a);
    for (int i = 0; i < H_a; i++) cin >> A[i];

    cin >> H_b >> W_b;
    vector<string> B(H_b);
    for (int i = 0; i < H_b; i++) cin >> B[i];

    cin >> H_x >> W_x;
    vector<string> X(H_x);
    for (int i = 0; i < H_x; i++) cin >> X[i];

    h_w_s_erase(H_a, W_a, A);
    h_w_s_erase(H_b, W_b, B);
    h_w_s_erase(H_x, W_x, X);

    if (max(H_a, H_b) > H_x || max(W_a, W_b) > W_x) {
        cout << "No" << endl;
        return 0;
    }

    vector<string> Y(H_x, string(W_x, '.'));

    for (int i_a = 0; i_a + H_a <= H_x; i_a++) {
        for (int j_a = 0; j_a + W_a <= W_x; j_a++) {
            for (int i_b = 0; i_b + H_b <= H_x; i_b++) {
                for (int j_b = 0; j_b + W_b <= W_x; j_b++) {
                    Y = vector<string>(H_x, string(W_x, '.'));

                    for (int i = 0; i < H_a; i++) {
                        for (int j = 0; j < W_a; j++) {
                            if (A[i][j] == '#') {
                                Y[i_a + i][j_a + j] = '#';
                            }
                        }
                    }

                    for (int i = 0; i < H_b; i++) {
                        for (int j = 0; j < W_b; j++) {
                            if (B[i][j] == '#') {
                                Y[i_b + i][j_b + j] = '#';
                            }
                        }
                    }

                    if (X == Y) {
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
