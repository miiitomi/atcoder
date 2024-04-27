#include <bits/stdc++.h>
using namespace std;

void solve() {
    string S;
    cin >> S;
    int N = S.size();

    vector<int> mp(N, -1);
    vector<int> idx;
    for (int i = 0; i < N; i++) {
        if (S[i] == '(') idx.push_back(i);
        else if (S[i] == ')') {
            int j = idx.back();;
            idx.pop_back();
            mp[i] = j;
            mp[j] = i;
        }
    }


    string ans = "";
    bool s = true;
    int i = 0;

    while (0 <= i && i < N) {
        if (s) {
            if (S[i] == '(') {
                s = !s;
                i = mp[i] - 1;
            } else if (S[i] == ')') {
                s = !s;
                i = mp[i] - 1;
            } else {
                ans.push_back(S[i]);
                i++;
            }
        } else {
            if (S[i] == '(') {
                s = !s;
                i = mp[i] + 1;
            } else if (S[i] == ')') {
                s = !s;
                i = mp[i] + 1;
            } else {
                if ('A' <= S[i] && S[i] <= 'Z') {
                    S[i] = ((S[i] - 'A') + 'a');
                } else {
                    S[i] = ((S[i] - 'a') + 'A');
                }
                ans.push_back(S[i]);
                i--;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
