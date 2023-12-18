// https://atcoder.jp/contests/abc285/tasks/abc285_d
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(N), T(N);
    map<string, int> mp1, mp2;
    
    set<string> Cur;
    for (int i = 0; i < N; i++) {
        cin >> S[i] >> T[i];
        mp1[S[i]] = i;
        mp2[T[i]] = i;
        Cur.insert(S[i]);
    }

    set<string> Can;
    for (int i = 0; i < N; i++) {
        if (!Cur.count(T[i])) {
            Can.insert(T[i]);
        }
    }

    vector<bool> done(N, false);
    int cnt = 0;
    while (!Can.empty()) {
        string t = *Can.begin();
        Can.erase(t);
        int i = mp2[t];
        done[i] = true;
        cnt++;
        string s = S[i];
        Cur.erase(s);
        if (mp2.count(s) && !done[mp2[s]]) {
            Can.insert(s);
        }
    }

    if (cnt == N) cout << "Yes" << endl;
    else cout << "No" << endl;
}
