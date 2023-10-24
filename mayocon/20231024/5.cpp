// https://atcoder.jp/contests/abc305/tasks/abc305_f
#include <bits/stdc++.h>
using namespace std;

int N, M;

bool dfs(int v, vector<int> &path, vector<bool> &done) {
    path.push_back(v);
    int K;
    cin >> K;
    vector<int> A(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < K; i++) {
        if (A[i] == N) {
            cout << N << endl;
            string s;
            cin >> s;
            return true;
        }
        A[i]--;
    }

    for (int i = 0; i < K; i++) {
        int a = A[i];
        if (done[a]) continue;
        done[a] = true;
        cout << a+1 << endl;
        bool ok = dfs(a, path, done);
        if (ok) return true;
        
        cin >> K;
        for (int j = 0; j < K; j++) {
            cin >> A[j];
            A[j]--;
        }
    }

    path.pop_back();

    cout << path.back()+1 << endl;
    return false;
}

int main() {
    cin >> N >> M;

    vector<bool> done(N, false);
    vector<int> path;
    done[0] = true;

    dfs(0, path, done);
}
