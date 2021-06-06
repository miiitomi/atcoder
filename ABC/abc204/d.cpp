#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> T(N);
    int summ = 0;
    for (int i = 0; i < N; i++) {
        cin >> T.at(i);
        summ += T.at(i);
    }

    vector<vector<bool>> dp(N, vector<bool>(summ + 1));
    dp.at(0).at(0) = true;
    dp.at(0).at(T.at(0)) = true;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < summ + 1; j++) {
            if (dp.at(i-1).at(j)) {
                dp.at(i).at(j) = true;
                if (j + T.at(i) < summ + 1) {
                    dp.at(i).at(j + T.at(i)) = true;
                }
            }
        }
    }

    int ans = summ;
    for (int j = 0; j < summ + 1; j++) {
        if (dp.at(N-1).at(j)) {
            int x = max(j, summ - j);
            ans = min(ans, x);
        }
    }

    cout << ans << endl;
}