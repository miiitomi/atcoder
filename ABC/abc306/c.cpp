#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(3*N);
    for (int i = 0; i < 3*N; i++) {
        cin >> A[i];
    }
    vector<int> C(N+1, 0);
    vector<int> ans;
    for (int a : A) {
        C[a]++;
        if (C[a] == 2) {
            ans.push_back(a);
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i];
        if (i < N-1) cout << " ";
        else cout << endl;
    }
}
