#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A;
    while (N--) {
        int a;
        cin >> a;
        if (A.size() >= 3 && A[A.size()-1] == a && A[A.size()-2] == a && A[A.size()-3] == a) {
            A.pop_back();
            A.pop_back();
            A.pop_back();
        } else {
            A.push_back(a);
        }
    }
    cout << A.size() << "\n";
}
