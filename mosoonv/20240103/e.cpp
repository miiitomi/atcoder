#include <bits/stdc++.h>
using namespace std;

int N, T, M;
vector<vector<int>> V;

void dfs(vector<int> v) {
    V.push_back(v);
    int i = T-1;
    for (int j = v.size()-2; j >= 0; j--) {
        if (v[j] >= 1) {
            i = j;
            break;
        }
    }

    if (i == T-1) return;

    for (int j = T-1; j > i+1; j--) {
        v[j-1] += v[j];
        v[j] = 0;
    }
    v[i]--;
    v[i+1]++;
    dfs(v);
}

int main() {
    cin >> N >> T >> M;

    vector<int> v(T, 0);
    v[0] = N-T;
    dfs(v);

    vector<int> A(M), B(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }

    set<vector<int>> st;
    for (vector<int> &v : V) {
        vector<int> w;
        for (int i = 0; i < T; i++) {
            w.push_back(i);
            for (int j = 0; j < v[i]; j++) w.push_back(i);
        }

        do {
            bool ok = true;
            for (int i = 0; i < M; i++) {
                if (w[A[i]] == w[B[i]]) {
                    ok = false;
                    break;
                }
            }
            if (ok) st.insert(w);
        } while (next_permutation(w.begin(), w.end()));
    }

    cout << st.size() << endl;
}
