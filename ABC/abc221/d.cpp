#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<int, int> M;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        M[a]++;
        M[a+b]--;
    }

    auto iter = M.begin();
    while (true) {
        int x = iter->second;
        iter++;
        if (iter == M.end()) break;
        else iter->second += x;
    }

    vector<int> A(N+1, 0);
    iter = M.begin();
    while (true) {
        int n = iter->second;
        int x = iter->first;
        iter++;
        if (iter == M.end()) break;
        else {
            A[n] += (iter->first) - x;
        }
    }
    for (int k = 1; k <= N; k++) {
        if (k < N) cout << A[k] << " ";
        else cout << A[k] << endl;
    }
}
