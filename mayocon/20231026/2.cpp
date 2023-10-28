// https://atcoder.jp/contests/abc279/tasks/abc279_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    swap(H, W);
    vector<string> S(H, string(W, '#')), T(H, string(W, '#')); 
    for (int w = 0; w < W; w++) {
        for (int h = 0; h < H; h++) {
            char c;
            cin >> c;
            S[h][w] = c;
        }
    }
    for (int w = 0; w < W; w++) {
        for (int h = 0; h < H; h++) {
            char c;
            cin >> c;
            T[h][w] = c;
        }
    }
    sort(S.begin(), S.end());
    sort(T.begin(), T.end());

    if (S == T) cout << "Yes" << endl;
    else cout << "No" << endl;
}
