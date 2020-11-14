#include <iostream>

/*
 * Старинная-добрая игра на страницах всех школьных тетрадей.
 * Поле размером 3х3 представлено в виде двумерного массива с типом элементов char.
 * Помните тот символьный тип из предыдущего модуля? Теперь он нам и пригодится.
 * Участвуют два игрока, которые ходят по очереди и ставят в указанные ими в стандартном вводе координаты
 *  свой символ - ‘X’ или ‘O’ (буквы латинского алфавита).
 * Как только у одного из игроков будет установлено подряд три крестика или три нолика - он побеждает.
 * Если свободных клеток не осталось, а трёх совпадающих элементов не найдено - объявляется ничья.
 * Для простоты, мы не будем рассматривать диагональные совпадения,
 *  а только строго вертикальные либо строго горизонтальные.
 *
 *  Изначально всё поле инициализируется символом пробела - ‘ ‘.
 *  Это можно сделать сразу при объявлении, либо с помощью вложенного цикла.
 *  На каждом ходе, при занятой клетке или при неверных координатах этой клетки должно быть выведено сообщение
 *   и игрок должен указать координаты клетки повторно.
 *  После каждого хода надо выводить в консоль текущее состояние всего игрового поля, для наглядности.
 *
 *  Проверку на победу игрока, которую надо осуществлять после каждого хода,
 *      можно сделать с помощью вложенного цикла,
 *      сразу проверяя и вертикаль и горизонталь а как именно - попробуйте догадаться сами.
 */

bool checkTie(char array[3][3]) {
    bool check = true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (array[i][j] == ' ') {
                check = false;
                break;
            }
        }
        if (check == false) {break;}
    }
    return check;
}

bool checkWin(char array[3][3]) {
    bool check = false;
    std::string strX = "xxx";
    std::string strO = "ooo";
    std::string height;
    std::string length;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            height += array[i][j];
            length += array[j][i];
        }
        if (height == strO || height == strX || length == strO || length == strX) {
            check = true;
            break;
        }
        height = "";
        length = "";
    }
    return check;
}

void printField(char array[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << array[i][j];
            if (j < 2) {std::cout << "|";}
        }
        std::cout << std::endl;
        if (i < 2) {std::cout << "------" << std::endl;}
    }
}

char changeSymbol(char a) {
    if (a == 'x') {
        a = 'o';
    } else {
        a = 'x';
    }
    return a;
}

int main() {

    char field[3][3] {' ', ' ', ' ',
                      ' ', ' ', ' ',
                      ' ', ' ', ' '};
    int a;
    int b;
    char symbol = 'x';

    while (!checkWin(field) && !checkTie(field)) {
        std::cout << "Enter you coordinates (a, b): ";
        std::cin >> a >> b;
        while (a > 2 || a < 0 || b > 2 || b < 0 || field[a][b] != ' ') {
            std::cout << "Please, once again: ";
            std::cin >> a >> b;
        }
        field[a][b] = symbol;
        printField(field);
        if (checkWin(field) == true) {
            std::cout << "You won!" << std::endl;
        }
        if (checkTie(field) == true) {
            std::cout << "It is tie!" << std::endl;
        }
        symbol = changeSymbol(symbol);
    }
}
