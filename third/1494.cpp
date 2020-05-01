#include <bits/stdc++.h>

using namespace std;

int main () {
    int n;
    cin >> n;
    int current;
    int max = 0;
    stack <int> balls;
    bool isCheater = false;
    for (int i = 0; i < n; i ++) {
        cin >> current;
        if (current <= max) {
            if (current == balls.top())
                balls.pop();
            else
                isCheater = true;
        } else {
            for (int c = max + 1; c < current; c ++)
                balls.push(c);
            max = current;
        }
    }
    if (isCheater) {
        cout << "Cheater" << endl;
    } else {
        cout << "Not a proof" << endl;

    }
    return 0;
}
