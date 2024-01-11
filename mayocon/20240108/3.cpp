// https://atcoder.jp/contests/abc136/tasks/abc136_d
#include <bits/stdc++.h>
using namespace std;

string S;
int N;
vector<vector<int>> v;

vector<int> rec(int i) {
    if (v[i][0] != -1) return v[i];
    if (S[i] == 'R' && S[i+1] == 'L') {
        v[i][0] = i;
        v[i][1] = i+1;
        return v[i];
    }
    if (S[i] == 'L' && S[i-1] == 'R') {
        v[i][0] = i;
        v[i][1] = i-1;
        return v[i];
    }
    if (S[i] == 'L') {
        v[i] = rec(i-1);
        swap(v[i][0], v[i][1]);
        return v[i];
    }
    if (S[i] == 'R') {
        v[i] = rec(i+1);
        swap(v[i][0], v[i][1]);
        return v[i];
    }
}

int main() {
    cin >> S;
    N = S.size();
    v.assign(N, vector<int>(2, -1));
    vector<int> cnt(N, 0);
    for (int i = 0; i < N; i++) {
        vector<int> res = rec(i);
        cnt[res[0]]++;
    }

    for (int c : cnt) cout << c << " ";
    cout << endl;
}
