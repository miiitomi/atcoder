#include <bits/stdc++.h>
using namespace std;

string S = "wbwbwwbwbwbw";

void solve() {
    string T = "";
    for (int k = 0; k < 100; k++) T += S;

    int W, B;
    cin >> W >> B;
    for (int i = 0; i < 20; i++) {
        int w = 0, b = 0;
        for (int j = 0; j < B+W; j++) {
            if (T[i+j] == 'w') w++;
            else b++;
        }
        if (w == W && b == B) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
