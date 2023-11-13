#include <bits/stdc++.h>
using namespace std;

int N;
string R, C;

bool f(vector<string> &S) {
    for (int i = 0; i < N; i++) {
        bool done = false;
        for (int j = 0; j < N; j++) {
            if (S[i][j] == R[i]) {
                done = true;
                break;
            } else if (S[i][j] == '.') {
                continue;
            } else {
                return false;
            }
        }
        if (!done) return false;
    }
    for (int i = 0; i < N; i++) {
        bool done = false;
        for (int j = 0; j < N; j++) {
            if (S[j][i] == C[i]) {
                done = true;
                break;
            } else if (S[j][i] == '.') {
                continue;
            } else {
                return false;
            }
        }
        if (!done) return false;
    }
    return true;
}

int main() {
    cin >> N >> R >> C;

    vector<int> a(N), b(N), c(N);
    for (int i = 0; i < N; i++) {
        a[i] = i;
        b[i] = i;
        c[i] = i;
    }

    do {
        do {
            do {
                vector<string> S(N, string(N, '.'));
                bool ok = true;
                for (int i = 0; i < N; i++) {
                    if (a[i] == b[i] || b[i] == c[i] || c[i] == a[i]) {
                        ok = false;
                        break;
                    }
                    S[i][a[i]] = 'A';
                    S[i][b[i]] = 'B';
                    S[i][c[i]] = 'C';
                }
                if (ok && f(S)) {
                    cout << "Yes" << endl;
                    for (string s : S) cout << s << endl;
                    return 0;
                }
            } while (next_permutation(c.begin(), c.end()));
        } while (next_permutation(b.begin(), b.end()));
    } while (next_permutation(a.begin(), a.end()));

    cout << "No" << endl;
    return 0;
}
