// https://atcoder.jp/contests/abc302/tasks/abc302_b
#include <bits/stdc++.h>
using namespace std;

string snuke = "snuke";

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    for (int i = 0; i < H; i++) {
        for (int j = 0; j+4 < W; j++) {
            bool ok = true;
            for (int k = 0; k < 5; k++) {
                if (S[i][j+k] != snuke[k]) ok = false;
            }
            if (ok) {
                for (int k = 0; k < 5; k++) cout << i+1 << " " << j+k+1 << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = W-1; j-4 >= 0; j--) {
            bool ok = true;
            for (int k = 0; k < 5; k++) {
                if (S[i][j-k] != snuke[k]) ok = false;
            }
            if (ok) {
                for (int k = 0; k < 5; k++) cout << i+1 << " " << j-k+1 << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i+4 < H; i++) {
        for (int j = 0; j < W; j++) {
            bool ok = true;
            for (int k = 0; k < 5; k++) {
                if (S[i+k][j] != snuke[k]) ok = false;
            }
            if (ok) {
                for (int k = 0; k < 5; k++) cout << i+k+1 << " " << j+1 << endl;
                return 0;
            }
        }
    }
    for (int i = H-1; i-4 >= 0; i--) {
        for (int j = 0; j < W; j++) {
            bool ok = true;
            for (int k = 0; k < 5; k++) {
                if (S[i-k][j] != snuke[k]) ok = false;
            }
            if (ok) {
                for (int k = 0; k < 5; k++) cout << i-k+1 << " " << j+1 << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i+4 < H; i++) {
        for (int j = 0; j+4 < W; j++) {
            bool ok = true;
            for (int k = 0; k < 5; k++) {
                if (S[i+k][j+k] != snuke[k]) ok = false;
            }
            if (ok) {
                for (int k = 0; k < 5; k++) cout << i+k+1 << " " << j+k+1 << endl;
                return 0;
            }
        }
    }
    for (int i = 0; i+4 < H; i++) {
        for (int j = W-1; j-4 >= 0; j--) {
            bool ok = true;
            for (int k = 0; k < 5; k++) {
                if (S[i+k][j-k] != snuke[k]) ok = false;
            }
            if (ok) {
                for (int k = 0; k < 5; k++) cout << i+k+1 << " " << j-k+1 << endl;
                return 0;
            }
        }
    }
    for (int i = H-1; i-4 >= 0; i--) {
        for (int j = 0; j+4 < W; j++) {
            bool ok = true;
            for (int k = 0; k < 5; k++) {
                if (S[i-k][j+k] != snuke[k]) ok = false;
            }
            if (ok) {
                for (int k = 0; k < 5; k++) cout << i-k+1 << " " << j+k+1 << endl;
                return 0;
            }
        }
    }
    for (int i = H-1; i-4 >= 0; i--) {
        for (int j = W-1; j-4 >= 0; j--) {
            bool ok = true;
            for (int k = 0; k < 5; k++) {
                if (S[i-k][j-k] != snuke[k]) ok = false;
            }
            if (ok) {
                for (int k = 0; k < 5; k++) cout << i-k+1 << " " << j-k+1 << endl;
                return 0;
            }
        }
    }
}
