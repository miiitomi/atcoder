#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A.at(i);
    }

    vector<int> B;
    for (int i = 0; i < N; i++) {
        if (A.at(i) != X) {
            B.push_back(A.at(i));
        }
    }

    for (int i = 0; i < B.size(); i++) {
        cout << B.at(i) << " ";
    }
    cout << endl;
}