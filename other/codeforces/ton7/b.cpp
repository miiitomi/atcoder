#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int cnt = 0;
    int r = N-1;

    for (int i = N-2; i >= 0; i--) {
        if (S[i] == 'A' && S[i+1] == 'B') {
            int j = i;
            while (j < r && S[j] == 'A' && S[j+1] == 'B') {
                swap(S[j], S[j+1]);
                cnt++;
                j++;
            }
            r = i;
        }
    }

    cout << cnt << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
