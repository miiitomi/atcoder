#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    set<int> S;
    S.insert(0);
    int v = 0;
    int w;
    while (true) {
        w = A[v];
        if (S.count(w)) {
            break;
        }
        S.insert(w);
        v = w;
    }

    vector<int> ans;
    ans.push_back(w);
    v = w;
    while (true) {
        v = A[v];
        if (v == w) break;
        ans.push_back(v);
    }

    cout << (int)ans.size() << endl;
    for (int v : ans) {
        cout << 1 + v << " ";
    }
    cout << endl;
}
