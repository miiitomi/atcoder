// https://atcoder.jp/contests/abc243/tasks/abc243_a
#include <bits/stdc++.h>
using namespace std;

string S = "FMT";

int main() {
    int V;
    vector<int> A(3);
    cin >> V >> A[0] >> A[1] >> A[2];

    while (true) {
        for (int i = 0; i < 3; i++) {
            if (V < A[i]) {
                cout << S[i] << endl;
                return 0;
            }
            V -= A[i];
        }
    }
}
