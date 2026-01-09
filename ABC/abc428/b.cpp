#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int ans = 0;
    vector<string> V;
    for (int i = 0; i+K <= N; i++) {
        int cnt = 0;
        for (int j = 0; j+K <= N; j++) {
            bool ok = true;
            for (int k = 0; k < K; k++) {
                if (S[i+k] != S[j+k]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                cnt++;
            }
        }
        if (ans <= cnt) {
            string s(K, 'a');
            for (int k = 0; k < K; k++) {
                s[k] = S[i+k];
            }
            if (ans < cnt) {
                V = vector<string>(1, s);
                ans = cnt;
            } else {
                V.push_back(s);
            }
        }
    }
    cout << ans << "\n";
    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());
    for (string s: V) cout << s << " ";
    cout << "\n";
}
