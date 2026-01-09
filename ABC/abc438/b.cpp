#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;
    int ans = 1e+9;
    for (int s = 0; s+M <= N; s++) {
        int tmp = 0;
        for (int i = 0; i < M; i++) {
            int x = S[s+i]-'0', y = T[i]-'0';
            if (x < y) x += 10;
            tmp += x-y;
        }
        ans = min(ans, tmp);
    }
    cout << ans << "\n";
}
