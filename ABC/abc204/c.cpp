#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> &V, vector<bool> &temp) {
    if (temp.at(i)) {
        return;
    }
    temp.at(i) = true;
    for (int v : V.at(i)) {
        dfs(v, V, temp);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> V(N, vector<int>(0));
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        V.at(a-1).push_back(b-1);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        vector<bool> temp(N, false);
        dfs(i, V, temp);
        for (int j = 0; j < N; j++) ans += temp.at(j);
    }
    
    cout << ans << endl;
}