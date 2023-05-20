#include <bits/stdc++.h>
using namespace std;

vector<string> v{"snuke", "ekuns"};

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            for (int x = 0; x < 2; x++) {
                string s = v[x];
                if (w + 4 < W) {
                    if (S[h][w] == s[0] && S[h][w+1] == s[1] && S[h][w+2] == s[2] && S[h][w+3] == s[3] && S[h][w+4] == s[4]) {
                        h++;
                        w++;
                        if (x == 0) {
                            for (int k = 0; k < 5; k++) {
                                cout << h << " " << w + k << endl;
                            }
                        } else {
                            for (int k = 0; k < 5; k++) {
                                cout << h << " " << w + 4 - k << endl;
                            }
                        }
                        return 0;
                    }
                }

                if (h + 4 < H) {
                    if (S[h][w] == s[0] && S[h+1][w] == s[1] && S[h+2][w] == s[2] && S[h+3][w] == s[3] && S[h+4][w] == s[4]) {
                        h++;
                        w++;
                        if (x == 0) {
                            for (int k = 0; k < 5; k++) {
                                cout << h + k << " " << w << endl;
                            }
                        } else {
                            for (int k = 0; k < 5; k++) {
                                cout << h + 4 - k << " " << w << endl;
                            }
                        }
                        return 0;
                    }
                }

                if (h + 4 < H && w + 4 < W) {
                    if (S[h][w] == s[0] && S[h+1][w+1] == s[1] && S[h+2][w+2] == s[2] && S[h+3][w+3] == s[3] && S[h+4][w+4] == s[4]) {
                        h++;
                        w++;
                        if (x == 0) {
                            for (int k = 0; k < 5; k++) {
                                cout << h + k << " " << w + k << endl;
                            }
                        } else {
                            for (int k = 0; k < 5; k++) {
                                cout << h + 4 - k << " " << w + 4 - k << endl;
                            }
                        }
                        return 0;
                    }
                }

                if (h + 4 < H && w - 4 >= 0) {
                    if (S[h][w] == s[0] && S[h+1][w-1] == s[1] && S[h+2][w-2] == s[2] && S[h+3][w-3] == s[3] && S[h+4][w-4] == s[4]) {
                        h++;
                        w++;
                        if (x == 0) {
                            for (int k = 0; k < 5; k++) {
                                cout << h + k << " " << w - k << endl;
                            }
                        } else {
                            for (int k = 0; k < 5; k++) {
                                cout << h + 4 - k << " " << w - 4 + k << endl;
                            }
                        }
                        return 0;
                    }
                }
            }
        }
    }
}
