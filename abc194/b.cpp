#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i) >> B.at(i);
    }

    int ans = 2 * pow(10, 5);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                ans = min(ans, A.at(i)+B.at(j));
            } else {
                ans = min(ans, max(A.at(i), B.at(j)));
            }
        }
    }

    cout << ans << endl;
}