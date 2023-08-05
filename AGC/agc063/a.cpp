#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    priority_queue<int, vector<int>, greater<int>> A, B;
    for (int i = 0; i < N+1; i++) {
        if (S[i] == 'A') A.push(i);
        else B.push(i);
    }

    for (int k = 1; k <= N; k++) {
        if (k % 2 == 1) {
            if (!B.empty()) {
                B.pop();
            }
        } else {
            if (!A.empty()) {
                A.pop();
            }
        }
        if (!A.empty() && !B.empty()) {
            if (A.top() < B.top()) cout << "Alice" << endl;
            else cout << "Bob" << endl;
        } else if (A.empty()) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
}
