#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N, "");
    map<string, bool> m;

    for (int i = 0; i < N; i++) {
        cin >> S[i];
        m[S[i]] = false;
    }
    for (int i = 0; i < M; i++) {
        string t;
        cin >> t;
        m[t] = true;
    }

    for (string s : S) {
        if (m[s]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
