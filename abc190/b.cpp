#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, S, D;
    cin >> N >> S >> D;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; i++) {
        cin >> X.at(i) >> Y.at(i);
    }

    string ans = "No";
    for (int i = 0; i < N; i++) {
        if (X.at(i) < S && Y.at(i) > D) {
            ans = "Yes";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}