// https://atcoder.jp/contests/abc236/tasks/abc236_d
#include <bits/stdc++.h>
using namespace std;
int N;
int ans = 0;
vector<vector<int>> A;

void score(vector<int> &v) {
    int tmp = 0;
    vector<bool> done(2*N, false);
    for (int i = 0; i < 2*N; i++) {
        if (done[i]) continue;
        int j = v[i];
        tmp ^= A[i][j];
        done[i] = true;
        done[j] = true;
    }
    ans = max(tmp, ans);
}

void dfs(vector<int> &v) {
    auto iter = find(v.begin(), v.end(), -1);
    if (iter == v.end()) {
        score(v);
        return;
    }
    int i = distance(v.begin(), iter);
    iter++;
    for (; iter != v.end(); iter++) {
        if (*iter != -1) continue;
        int j = distance(v.begin(), iter);
        v[i] = j;
        v[j] = i;
        dfs(v);
        v[i] = -1;
        v[j] = -1;
    }
}

int main() {
    cin >> N;
    A.assign(2*N, vector<int>(2*N, 0));

    for (int i = 0; i < 2*N-1; i++) {
        for (int j = i+1; j < 2*N; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> v(2*N, -1);
    dfs(v);

    cout << ans << endl;
}
