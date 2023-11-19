#include <bits/stdc++.h>
using namespace std;

int N, M;
string S, T;

bool f(int i) {
    bool ok = true;
    bool update = false;
    for (int k = 0; k < M; k++) {
        if (S[i+k] != T[k] && S[i+k] != '#') {
            ok = false;
            break;
        }
        if (S[i + k] != '#') update = true;
    }

    if (ok && update) {
        for (int k = 0; k < M; k++) S[i+k] = '#';
        return true;
    }
    return false;
}

int main() {
    cin >> N >> M >> S >> T;

    queue<int> Q;
    for (int i = 0; i <= N-M; i++) Q.push(i);

    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        bool done = f(x);
        if (done) {
            for (int i = max(0, x -M+1); i <= min(N-M, x+M-1); i++) Q.push(i);
        }
    }

    if (S == string(N, '#')) cout << "Yes" << endl;
    else cout << "No" << endl;
}
