// https://atcoder.jp/contests/abc315/tasks/abc315_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    vector<vector<int>> r(H, vector<int>(26, 0)), c(W, vector<int>(26, 0));
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            int s = (int)(S[h][w] - 'a');
            r[h][s]++;
            c[w][s]++;
        }
    }
    unordered_set<int> remain_h, remain_w;
    for (int h = 0; h < H; h++) remain_h.insert(h);
    for (int w = 0; w < W; w++) remain_w.insert(w);
    int rH = H, rW = W;
    vector<int> delete_h, delete_w;
    vector<int> cnt_r(H, 0), cnt_c(W, 0);
    for (int h = 0; h < H; h++) for (int s = 0; s < 26; s++) if (r[h][s] > 0) cnt_r[h]++;
    for (int w = 0; w < W; w++) for (int s = 0; s < 26; s++) if (c[w][s] > 0) cnt_c[w]++;

    while (rH >= 2 && rW >= 2) {
        for (int h : remain_h) {
            if (cnt_r[h] == 1) delete_h.push_back(h);
        }
        for (int w : remain_w) {
            if (cnt_c[w] == 1) delete_w.push_back(w);
        }

        if (delete_h.size() == 0 && delete_w.size() == 0) break;

        for (int h : delete_h) {
            remain_h.erase(h);
            for (int w : remain_w) {
                c[w][(int)(S[h][w] - 'a')]--;
                if (c[w][(int)(S[h][w] - 'a')] == 0) cnt_c[w]--;
            }
            rH--;
        }
        for (int w : delete_w) {
            remain_w.erase(w);
            for (int h : remain_h) {
                r[h][(int)(S[h][w] - 'a')]--;
                if (r[h][(int)(S[h][w] - 'a')] == 0) cnt_r[h]--;
            }
            rW--;
        }
        delete_h.resize(0);
        delete_w.resize(0);
    }

    cout << rH * rW << endl;
}
