#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> S(N-1);
    int a_new = 0;
    int a_old = 0;
    for (int i = 0; i < N; i++) {
        a_old = a_new;
        cin >> a_new;
        if (i == 0) continue;
        S[i-1] = abs(a_new - a_old); 
    }
    sort(S.begin(), S.end());
    int ans = 0;
    for (int i = 0; i < (N-1)-(K-1); i++) ans += S[i];
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) solve();    
}
