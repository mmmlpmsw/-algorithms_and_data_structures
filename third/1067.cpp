#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//1067. Disk Tree
class Directory;

class Directory {
public:
    Directory() {}

    Directory *getDirectory(string const name) {
        if (directory_content.find(name) != directory_content.end()) {
            //нашел - возвращает найденный
            return directory_content[name];
        } else {
            // не нашел - создает
            directory_content[name] = new Directory();
            return directory_content[name];
        }
    }

    void getOrder(string tab_current) {
        string tab = " ";
        tab += tab_current;

        map<string, Directory *> sorted_content(directory_content.begin(), directory_content.end());
        map<string, Directory *>::iterator it;

        for (it = sorted_content.begin(); it != sorted_content.end(); it++) {
            cout << tab_current << it->first << endl;  // выводим ключ - название данной директории
            it->second->getOrder(tab); //рекурсия к содержимому
        }
    }

private:
    map<string, Directory *> directory_content;

};

int main() {
    int count;
    cin >> count;

    Directory *root = new Directory();

    string s;

    for (int i = 0; i <= count; i++) {

        getline(cin, s);
        stringstream path(s);

        Directory *current = root;
        //getline - извлекает данные из входного потока до строкового разделителя,
        // который не записывается в получившийся массив данных
        //3 параметра:
        // stream - это поток данных,
        // string – переменная, в которую запишется строка и
        // separator – строковый разделитель, показывающий на конец строки
        while (getline(path, s, '\\')) {
            // пока строка разбивается, извлекаем из нее уже имеющиеся или новые директории
            current = current->getDirectory(s);
        }
    }
    // запускаем создание дерева ответа
    root->getOrder("");

    return 0;
}

