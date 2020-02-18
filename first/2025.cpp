//
// Created by mmmlpmsw on 10.02.2020.
//

#include <iostream>
//2025. Стенка на стенку
using namespace std;
int main() {

    int testCounter;
    cin >> testCounter;
    int n, k; //бойцов и команд соответственно
    for (int i = 0; i < testCounter; i ++) {
        cin >> n >> k;
        // количество участников обычной команды
        int membersOfCommonCommand = n / k;

        //количество расширенных команд
        int amountOfExtendedCommands = n % k;

        //количество участников расширенной команды
        int membersOfExtendedCommand = membersOfCommonCommand + 1;

        //всего участников в расширенных командах
        int allMembersOfExtendedCommands = amountOfExtendedCommands * membersOfExtendedCommand;

        //всего участников в обычных командах
        int allMembersOfCommonCommands = n - allMembersOfExtendedCommands;

        //соперников одной обычной команды
        int commonVsAmount = n - membersOfCommonCommand;

        //соперников одной расширенной команды
        int extendedVsAmount = n - membersOfExtendedCommand;

        cout << ((allMembersOfCommonCommands * commonVsAmount)+(allMembersOfExtendedCommands * extendedVsAmount)) / 2 << endl;
    }
    return 0;
}

//Время работы – линейное

