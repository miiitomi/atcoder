#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    int x = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        x ^= A[i];
    }

    if (x != 0) {
        cout << -1 << endl;
        return 0;
    }

    sort(A.begin(), A.end());

    while (A.size() >= 2 && A[A.size()-1] == A[A.size()-2]) {
        A.pop_back();
        A.pop_back();
    }

    if (A.empty() || A.back() == 1) {
        cout << 0 << endl;
    } else {
        cout << A.back()-1 << endl;
    }
}
