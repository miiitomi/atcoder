#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<int> A(26, 0);
    for (char c : S) A[(int)(c - 'a')]++;

    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        cnt += A[i]/2;
    }

    if (cnt >= (N - K)/2) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
