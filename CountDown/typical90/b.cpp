#include <bits/stdc++.h>
using namespace std;

bool is_correct(string S) {
    int cnt = 0;
    for (char c : S) {
        if (c == '(') cnt++;
        else cnt--;
        if (cnt < 0) return false;
    }
    return cnt == 0;
}

int main() {
    int N;
    cin >> N;

    string S(N, '(');
    set<string> V;
    for (int s = 0; s < (1 << N); s++) {
        for (int k = 0; k < N; k++) {
            if (s & (1 << k)) S[k] = ')';
            else S[k] = '(';
        }
        if (is_correct(S)) V.insert(S);
    }

    for (string s : V) {
        cout << s << endl;
    }
}
