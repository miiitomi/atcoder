#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    if (K % 2 == 0) {
        sort(S.begin(), S.end());
        cout << S << endl;
        return;
    }

    string S1(N - N/2, 'a'), S2(N/2, 'a');
    int k = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) S1[k] = S[i];
        else {
            S2[k] = S[i];
            k++;
        }
    }
    sort(S1.begin(), S1.end());
    sort(S2.begin(), S2.end());
    k = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) cout << S1[k];
        else {
            cout << S2[k];
            k++;
        }
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}