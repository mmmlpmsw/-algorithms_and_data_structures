#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct City {
    long long money;
    int days;
} city[10000 + 50000];


struct Person {
    long long money;
    City *location;
} person[10000];


map<string, Person *> human;
map<string, City *> world;
set<pair<long long, City *>, greater<>> score;


int main() {
    ios_base::sync_with_stdio(false);


    int n;
    cin >> n;


    int counter = 0;
    for (int i = 0; i < n; ++i) {
        string nameOfPerson;
        string nameOfCity;
        long long money;
        cin >> nameOfPerson >> nameOfCity >> money;
        if (world[nameOfCity] != nullptr) {
            world[nameOfCity]->money += money;
        } else {
            city[counter].money = money;
            world[nameOfCity] = &city[counter];
            counter++;
        }
        person[i].money = money;
        person[i].location = world[nameOfCity];
        human[nameOfPerson] = &person[i];
    }


    for (auto &item : world) {
        score.insert({item.second->money, item.second});
    }


    int m, k, today = 0;
    cin >> m >> k;


    for (int i = 0; i < k; ++i) {
        int day;
        string name_p, name_c;
        cin >> day >> name_p >> name_c;
        int count = day - today;
        today = day;
        auto it2 = score.begin();
        auto it = it2++;
        if (it2 == score.end() || it->first > it2->first) {
            it->second->days += count;
        }
        City *to_city = world[name_c];
        Person *which_pers = human[name_p];
        if (to_city == nullptr) {
            world[name_c] = &city[counter];
            counter++;
            to_city = world[name_c];
        }
        score.erase({which_pers->location->money, which_pers->location});
        score.erase({to_city->money, to_city});
        which_pers->location->money -= which_pers->money;
        score.insert({which_pers->location->money, which_pers->location});
        which_pers->location = to_city;
        to_city->money += human[name_p]->money;
        score.insert({to_city->money, to_city});
    }


    int count = m - today;
    auto it2 = score.begin();
    auto it = it2++;
    if (it2 == score.end() || it->first > it2->first) {
        it->second->days += count;
    }


    for (auto &item : world) {
        if (item.second->days > 0)
            cout << item.first << " " << item.second->days << "\n";
    }
    return 0;
}
