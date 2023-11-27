#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int cnt = 0, tmp = 0, emp = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '.') {
            emp++;
            tmp++;
        } else {
            cnt = max(cnt, tmp);
            tmp = 0;
        }
    }
    cnt = max(cnt, tmp);

    if (cnt >= 3) cout << 2 << endl;
    else cout << emp << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
