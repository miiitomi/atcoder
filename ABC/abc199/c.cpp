#include <bits/stdc++.h>
using namespace std;

void f(string &X, string &Y, int t, int a, int b, int N) {
    if (t == 2) {
        swap(X, Y);
        return;
    }
    
    if (a < N && b < N) {
        swap(X.at(a), X.at(b));
    } else if (a < N && b >= N) {
        swap(X.at(a), Y.at(b-N));
    } else if (a >= N && b < N) {
        swap(Y.at(a-N), X.at(b));
    } else if (a >= N && b >= N) {
        swap(Y.at(a-N), Y.at(b-N));
    }
    return;
}

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    vector<int> T(Q), A(Q), B(Q);
    for (int i = 0; i < Q; i++) {
        cin >> T.at(i) >> A.at(i) >> B.at(i);
    }

    string X(N, 'a');
    for (int i = 0; i < N; i++) {
        X.at(i) = S.at(i);
    }
    string Y(N, 'a');
    for (int i = 0; i < N; i++) {
        Y.at(i) = S.at(N+i);
    }
    
    for (int i = 0; i < Q; i++) {
        f(X, Y, T.at(i), A.at(i)-1, B.at(i)-1, N);
    }

    cout << X << Y << endl;
}