// https://atcoder.jp/contests/abc062/tasks/abc062_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    cout << string(W+2, '#') << endl;
    for (int i = 0; i < H; i++) cout << '#' << S[i] << '#' << endl;
    cout << string(W+2, '#') << endl;
}
