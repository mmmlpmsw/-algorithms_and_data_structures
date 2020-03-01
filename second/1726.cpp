#include <iostream>

// 1726. Кто ходит в гости…

using namespace std;

long long n, x[100005], y[100005], sum = 0;

bool compare(long long a1, long long a2) {
    return a1 < a2;
}

void sort(long long arr[], int left, int right) {
    int i = left;
    int j = right;

    int t = arr[(left + right) / 2];

    while (i <= j) {
        while (compare(arr[i], t)) {
            i++;
        }
        while (compare(t, arr[j])) {
            j--;
        }

        if (i <= j) {
            long long t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
            j--;
        }
    }

    if (i < right) {
        sort(arr, i, right);
    }
    if (left < j) {
        sort(arr, left, j);
    }
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i ++) {
        cin >> x[i] >> y[i];
    }

    sort(x, 0, n - 1);
    sort(y, 0, n - 1);

    for (int i = 1; i < n; i ++) {
        sum += (x[i] - x[i - 1]) * i * (n - i) * 2;
        sum += (y[i] - y[i - 1]) * i * (n - i) * 2;
    }

    cout << sum /((n - 1) * n) << endl;

    return 0;
}
