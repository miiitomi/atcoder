// https://atcoder.jp/contests/abc300/tasks/abc300_b
#include <bits/stdc++.h>
using namespace std;
int H, W;

bool f(vector<string> A, vector<string> B, int s, int t) {
    for (int k = 0; k < s; k++) for (int j = 0; j < W; j++) {
        int a = A[0][j];
        for (int i = 0; i < H-1; i++) A[i][j] = A[i+1][j];
        A[H-1][j] = a;
    }

    for (int k = 0; k < t; k++) for (int i = 0; i < H; i++) {
        int a = A[i][0];
        for (int j = 0; j < W-1; j++) A[i][j] = A[i][j+1];
        A[i][W-1] = a;
    }

    if (A == B) return true;
    else return false;
}

int main() {
    cin >> H >> W;

    vector<string> A(H), B(H);
    for (int i = 0; i < H; i++) cin >> A[i];
    for (int j = 0; j < H; j++) cin >> B[j];

    for (int s = 0; s <= 30; s++) {
        for (int t = 0; t <= 30; t++) {
            if(f(A, B, s, t)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}
