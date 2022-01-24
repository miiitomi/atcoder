#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<vector<int>> table(N+1, vector<int>(26, N));
    for (int i = N-1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if ((int)(S[i] - 'a') == j) {
                table[i][j] = i;
            } else {
                table[i][j] = table[i+1][j];
            }
        }
    }

    string ans = "";
    int i = 0;
    while (K > 0) {
        K--;
        for (int j = 0; j < 26; j++) {
            if (table[i][j] + K < N) {
                ans.push_back((char)((int)'a' + j));
                i = table[i][j] + 1;
                break;
            }
        }
    }
    cout << ans << endl;
}
