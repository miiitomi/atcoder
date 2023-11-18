#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;
    deque<int> A;
    int mv = 2e+9;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        A.push_back(a);
        mv = min(mv, a);
    }

    int cnt = 0;
    while (A.front() != mv) {
        A.pop_front();
        cnt++;
    }

    for (int i = 0; i < (int)A.size()-1; i++) {
        if (!(A[i] <= A[i+1])) {
            cout << -1 << endl;
            return;
        }
    }

    cout << cnt << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) solve();
}
