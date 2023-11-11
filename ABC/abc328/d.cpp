#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    cin >> S;
    string A;
    char nc = 'A';

    for (char s : S) {
        if (s == nc) {
            if (nc == 'C') {
                A.pop_back();
                A.pop_back();
                if (!A.empty() && A.back() == 'A') nc = 'B';
                else if (A.size() > 1 && A.back() == 'B' && A[A.size() - 2] == 'A') nc = 'C';
                else nc = 'A';
            } else {
                A.push_back(s);
                nc++;
            }
        } else {
            if (nc != 'A') {
                nc = 'A';
            }
            A.push_back(s);
            if (s == 'A') {
                nc++;
            }
        }
    }

    cout << A << endl;
}
