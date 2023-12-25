#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> S(5001, vector<int>(5001, 0)); 

    while (N--) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        S[max(0, A-K)][max(0, B-K)]++;
        S[max(0, A-K)][B+1]--;
        S[A+1][max(0, B-K)]--;
        S[A+1][B+1]++;
    }

    for (int i = 0; i <= 5000; i++) {
        for (int j = 0; j < 5000; j++) S[i][j+1] += S[i][j];
    }
    for (int j = 0; j <= 5000; j++) {
        for (int i = 0; i < 5000; i++) S[i+1][j] += S[i][j];
    }

    int ans = -1;
    for (int i = 0; i < 5000; i++) for (int j = 0; j < 5000; j++) ans = max(ans, S[i][j]);
    cout << ans << endl;
}
