#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> S(N);
    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> S[i] >> A[i];
    }

    auto iter = min_element(A.begin(), A.end());
    
    for (int i = 0; i < N; i++) {
        cout << S[(int)distance(A.begin(), iter)] << endl;
        iter++;
        if (iter == A.end()) {
            iter = A.begin();
        }
    }
}
