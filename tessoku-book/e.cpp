#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int ans = 0;

    for (int a = 1; a <= N; a++) {
        for (int b = 1; b <= N; b++) {
            int c = K - a - b;
            if (c >= 1 && c <= N) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}
