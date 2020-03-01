#include <iostream>
#include <bits/stdc++.h>

// 1604. В Стране Дураков

using namespace std;

typedef struct {
    int count;
    int index;
} sign;


int main() {
    int n;
    cin >> n;

    sign signs[n];
    int min_count = 10001, max_count = 0, min_index = -1, max_index = -1;

    //считываем и определяем максимум и минимум
    for (int i = 0; i < n; i ++) {
        cin >> signs[i].count;
        signs[i].index = i + 1;
        if (signs[i].count >= max_count) {
            max_count = signs[i].count;
            max_index = i;
        }
        if (signs[i].count < min_count) {
            min_count = signs[i].count;
            min_index = i;
        }
    }

    // пока, идя с разных концов нашего массива, указатели на начало и конец не встретятся
    while (min_index != max_index && min_count != 10001) {
        printf("%i %i ", signs[max_index].index, signs[min_index].index);
        signs[max_index].count--;
        signs[min_index].count--;
        max_count = 0;
        min_count = 10001;
        for (int i = 0; i < n; i++) {
            if (signs[i].count != 0 && signs[i].count >= max_count) {
                max_count = signs[i].count;
                max_index = i;
            }
            if (signs[i].count != 0 && signs[i].count < min_count) {
                min_count = signs[i].count;
                min_index = i;
            }
        }
    }
    //выводим те, что остались без пары
    for (int i = 0; i < max_count; i++) {
        printf("%i ", signs[max_index].index);
    }
    return 0;
}
