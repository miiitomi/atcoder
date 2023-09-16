#include <bits/stdc++.h>
using namespace std;

string S;

bool is_kaibun(int x, int y) {
    for (int i = 0; x + i <= y; i++) {
        if (S[x+i] != S[y-i]) return false;
    }
    return true;
}

int main() {
    int ans = -1;
    cin >> S;
    int N = S.size();
    for (int x = 0; x < N; x++) {
        for (int y = x; y < N; y++) {
            if (is_kaibun(x, y)) {
                ans = max(ans, y - x + 1);
            }
        }
    }
    cout << ans << endl;
}
