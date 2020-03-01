//
// Created by mmmlpmsw on 23.02.2020.
//

#include <iostream>
#include <bits/stdc++.h>

// 1207. Медиана на плоскости

using namespace std;

typedef struct {
    long x;
    long y;
    long n;
    double angle;
} point;

long y_min = 1000001;
long y_min_num = 0;
const double PI = 3.14159265358979323846;

int main() {

    int n;
    cin >> n;

    point points[n];

    for (long i = 0; i < n; i ++) {
        cin >> points[i].x >> points[i].y;
        points[i].n = i + 1;

        // поиск минимальной (нижней левой) точки (д.б. строго минимальной по y, по х - возможно и не самая левая)
        if (points[i].y < y_min ||
            (points[i].y == y_min && points[i].x < points[y_min_num].x)) {
            y_min = points[i].y;
            y_min_num = i;
        }
    }

    //для удобства поменяем местами первый элемент массива и минимальную точку
    point tmp = points[0];
    points[0] = points[y_min_num];
    points[y_min_num] = tmp;

    //вычисляем углы, приводим их к одному способу выражения - положительные
    for (long i = 1; i < n; i ++) {
        if (points[i].x == points[0].x)
            points[i].angle = PI/2;
        else if (points[i].y == points[0].y)
            points[i].angle = 0;
        else
            points[i].angle = atan((double)(points[i].y - points[0].y) / (double)(points[i].x - points[0].x));

        if (points[i].angle < 0) points[i].angle += 2 * PI;
    }

    // сортиров очка по углу пузырьком
    for (long i = 1; i < (n - 1); i ++) {
        for (long j = (i + 1); j < n; j ++) {
            if (points[i].angle > points[j].angle) {
                point t = points[i];
                points[i] = points[j];
                points[j] = t;
            }
        }
    }

    cout << points[0].n << ' ' << points[n/2].n << endl;

    return 0;
}

