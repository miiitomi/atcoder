// https://atcoder.jp/contests/abc159/tasks/abc159_e
#include <bits/stdc++.h>
using namespace std;

int H, W, K;
vector<string> S;

int cnt(int s) {
    int ans = -1;
    vector<vector<int>> v;
    vector<int> tmp;
    for (int i = 0; i < H; i++) {
        tmp.push_back(i);
        if (s & (1 << i) || i == H-1) {
            v.push_back(tmp);
            tmp.resize(0);
            ans++;
        }
    }

    vector<int> w((int)v.size(), 0);
    for (int j = 0; j < W; j++) {
        for (int k = 0; k < (int)v.size(); k++) {
            bool is_empty = (w[k] == 0);
            for (int i  : v[k]) {
                if (S[i][j] == '1') {
                    w[k]++;
                }
            }
            if (w[k] > K) {
                if (is_empty) return 1e+9;
                ans++;
                w.assign((int)v.size(), 0);
                j--;
                break;
            }
        }
    }

    return ans;
}

int main() {
    cin >> H >> W >> K;
    S.resize(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    int ans = 1e+9;
    for (int s = 0; s < (1 << (H-1)); s++) {
        ans = min(ans, cnt(s));
    }

    cout << ans << endl;
}
