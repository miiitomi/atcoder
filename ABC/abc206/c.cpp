#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, int> M;
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
        if (M.count(A.at(i))) {
            M[A.at(i)]++;
        } else {
            M[A.at(i)] = 1;
        }
    }

    int64_t ans = 0;
    for (int i = 0; i < N; i++) {
        ans += N - M[A.at(i)];
    }

    cout << ans / 2 << endl;
}
