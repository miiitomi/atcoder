#include <bits/stdc++.h>
using namespace std;

void func() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for (int a : A) {
        if (a % 2 == 1) {
            ans++;
        }
    }

    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        func();
    }
}
