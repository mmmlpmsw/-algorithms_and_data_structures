#include <iostream>
// 1322 Шпион
//http://neerc.ifmo.ru/wiki/index.php?title=%D0%9F%D1%80%D0%B5%D0%BE%D0%B1%D1%80%D0%B0%D0%B7%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5_%D0%91%D0%B0%D1%80%D1%80%D0%BE%D1%83%D0%B7%D0%B0-%D0%A3%D0%B8%D0%BB%D0%B5%D1%80%D0%B0
//Преобразование Барроуза-Уилера

using namespace std;

bool compare(pair<char, int> a, pair<char, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

const int MAX_N = 100001;
pair<char, int> arr[MAX_N];

void sort(int left, int right) {
    int i = left;
    int j = right;

    pair<char, int> x = arr[(left + right) / 2];

    while (i <= j) {
        while (compare(arr[i], x)) {
            i++;
        }
        while (compare(x, arr[j])) {
            j--;
        }

        if (i <= j) {
            swap(arr[i], arr[j]);

            i++;
            j--;
        }
    }

    if (i < right) {
        sort(i, right);
    }
    if (left < j) {
        sort(left, j);
    }
}

int main() {
    string s;
    int number;
    cin >> number >> s;
    number--;

    int n = s.length();

    for (int i = 0; i < n; i++) {
        arr[i].first = s[i];
        arr[i].second = i;
    }

    sort(0, n - 1);

    // запоминаем порядок в котором переставляли элементы
    int ans[n];

    for (int i = 0; i < n; i++) {
        ans[i] = arr[i].second;
    }

    int cur = number;

    for (int i = 0; i < n; i++) {
        cout << arr[cur].first;
        cur = ans[cur];
    }

    return 0;
}

