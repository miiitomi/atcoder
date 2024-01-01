// https://atcoder.jp/contests/abc171/tasks/abc171_e
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

    for (int i = 0; i< N; i++) cout << (x ^ A[i]) << " ";
    cout << endl;
}
