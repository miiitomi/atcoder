#include <bits/stdc++.h>
using namespace std;

int N, M;

int cmp(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        if (a[i] != b[i]) cnt++;
    }
    return cnt;
}

int main() {
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    vector<vector<bool>> V(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cmp(S[i], S[j]) <= 1) {
                V[i][j] = true;
            }
        }
    }

    vector<int> v(N);
    for (int i = 0; i < N; i++) v[i] = i;

    do {
        bool flag = true;
        for (int i = 0; i < N-1; i++) {
            if (!V[v[i]][v[i+1]]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(v.begin(), v.end())); 

    cout << "No" << endl;
}
