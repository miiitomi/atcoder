#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A.at(i);

    int a_max = A.at(0);
    for (int i = 0; i < N; i++) {
        if (a_max < A.at(i)) a_max = A.at(i);
    }

    vector<int> B(a_max+2, 0);
    for (int i= 0; i < M; i++) B.at(A.at(i))++;

    set<int> S;
    for (int i = 0; i < B.size(); i++) {
        if (B.at(i) == 0) S.insert(i);
    }

    int ans = *begin(S);

    for (int i = 0; M + i < N; i++) {
        B.at(A.at(i))--;
        if (B.at(A.at(i)) == 0) S.insert(A.at(i));

        B.at(A.at(M+i))++;
        if (B.at(A.at(M+i)) == 1) S.erase(A.at(M+i));

        if (ans > *begin(S)) ans = *begin(S);
    }

    cout << ans << endl;
}