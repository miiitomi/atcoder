// https://atcoder.jp/contests/abc315/tasks/abc315_e
#include <bits/stdc++.h>
using namespace std;

void rec(int i, vector<bool> &done, vector<int> &v, vector<vector<int>> &P) {
    for (int j : P[i]) {
        if (!done[j]) rec(j, done, v, P);
    }
    v.push_back(i);
    done[i] = true;
    return;
}

int main() {
    int N;
    cin >> N;
    vector<int> C(N);
    vector<vector<int>> P(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        for (int j = 0; j < C[i]; j++) {
            int p;
            cin >> p;
            p--;
            P[i].push_back(p);
        }
    }

    vector<bool> done(N, false);
    vector<int> v;
    rec(0, done, v, P);
    v.pop_back();

    for (int i : v) cout << i+1 << " ";
    cout << endl;
}
