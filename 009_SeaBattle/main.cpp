#include <iostream>
#include <cmath>
/*
 * Требуется реализовать упрощённую игру в Морской бой. Игровое поле размером 10 на 10 клеток.
 * Участвует двое игроков. В арсенале каждого из них: 4 маленьких кораблика размером в одну клетку,
 *  3 небольших корабля размером в две клетки, 2 средних корабля размером в три клетки
 *  и один большой корабль размером в четыре клетки.
 * Для простоты, клетки поля пронумерованы по вертикали от 0 до 9, и по горизонтали также от 0 до 9.
 * Мы не будем использовать классические наименования клеток, такие как B4, C6, а просто два индекса.
 * Вначале игроки по очереди расставляют корабли, начиная с самых маленьких и заканчивая большими.
 * Маленькие корабли в одну клетку расставляются с помощью указания лишь одной клетки-точки на поле, к примеру 2,1.
 * Корабли размерностью от двух клеток и выше, расставляются с помощью координат их начала и конца, к примеру: 0,1 - 0,3.
 * Корабли могут быть установлены только строго вертикально, или горизонтально.
 * Установка корабля по диагонали - недопустимо, в случае которого об этом тоже надо сообщить пользователю.
 * Если корабль не может быть размещён на заданных клетках из-за того,
 *  что он столкнётся с другим кораблём (окажется на его клетках) или выйдет за пределы поля вообще,
 *  то игроку должно быть сделано предупреждение, после которого он должен переставить корабль
 *  на новые валидные координаты.
 * Замечу, в нашем упрощённом варианте игры, мы не будем обсчитывать соприкосновения кораблей друг с другом,
 *  а потому корабли вполне можно будет размещать друг к другу вплотную - борт к борту.
 * После того как все корабли были расставлены начинается игра.
 * Игроки по очереди атакуют друг друга, называя координаты выстрела.
 * После выстрела, в консоль выводится информация о его результате: попал или мимо.
 * Если выстрел успешен, клетка, на которой был корабль (или его фрагмент) затирается и становится пустой.
 * Игра заканчивается тогда, когда все корабли одной из сторон будут полностью уничтожены.
 * Как только это произойдёт в консоль выводится информация с номером игрока, который победил.
 */
bool CheckLocation(int field[10][10], int start1, int end1, int start2, int end2) {
    for (int i = std::min(start1, start2); i <= std::max(start1, start2); i++) {
        for (int j = std::min(end1, end2); j <= std::max(end1, end2); j++) {
            if (field[i][j] = ' ') {
                return false;
            }
        }
    }
    return true;
}

bool CheckCoordinate(int a) {
    if (a > 9 || a < 0) {
        return false;
    } else {
        return true;
    }
}

int InstallShips(int arr[10][10]) {

    int start1, end1, start2, end2;

    int tiny = 4;
    int small = 3;
    int big = 2;
    int huge = 1;
    while (tiny > 0) {

        std::cout << tiny << " ships left" << std::endl;
        std::cout << "Input coordinate of tiny ship:";
        std::cin >> start1 >> end1;
        while (!CheckCoordinate(start1) || !CheckCoordinate(end1)) {
            std::cout << "Wrong input. Try again";
            std::cin >> start1 >> end1;
        }
        if (CheckLocation(arr, start1, end1, start2, end2)) {
            arr[start1][end1] = ' ';
            tiny--;
        } else {
            std::cout << "Position of the ship is already filled. Try again" << std::endl;
        }
    }
    while (small > 0) {
        std::cout << small << " ships left" << std::endl;
        std::cout << "Input first coordinate of small ship:";
        std::cin >> start1 >> end1;
        std::cout << "Input second coordinate of small ship:";
        std::cin >> start2 >> end2;
        while (!CheckCoordinate(start1) || !CheckCoordinate(end1) || !CheckCoordinate(start2)
                || !CheckCoordinate(end2) || (abs(start1 - start2) > 0 && abs(end1 - end2) > 0)
                || abs(start1 - start2) != 2 || abs(end1 - end2) != 2) {
            std::cout << "Wrong input. Try again" << std::endl;
            std::cout << "Input first coordinate of small ship:";
            std::cin >> start1 >> end1;
            std::cout << "Input second coordinate of small ship:";
            std::cin >> start2 >> end2;
        }
        if (CheckLocation(arr, start1, end1, start2, end2)) {
            for (int i = std::min(start1, start2); i <= std::max(start1, start2); i++) {
                for (int j = std::min(end1, end2); j <= std::max(end1, end2); j++) {
                    arr[i][j] = ' ';
                }
            }
            small--;
        } else {
            std::cout << "Position of the ship is already filled. Try again" << std::endl;
        }
    }
    while (big > 0) {
        std::cout << big << " ships left" << std::endl;
        std::cout << "Input first coordinate of big ship:";
        std::cin >> start1 >> end1;
        std::cout << "Input second coordinate of big ship:";
        std::cin >> start2 >> end2;
        while (!CheckCoordinate(start1) || !CheckCoordinate(end1) || !CheckCoordinate(start2)
               || !CheckCoordinate(end2) || (abs(start1 - start2) > 0 && abs(end1 - end2) > 0)
               || abs(start1 - start2) != 3 || abs(end1 - end2) != 3) {
            std::cout << "Wrong input. Try again" << std::endl;
            std::cout << "Input first coordinate of small ship:";
            std::cin >> start1 >> end1;
            std::cout << "Input second coordinate of small ship:";
            std::cin >> start2 >> end2;
        }
        if (CheckLocation(arr, start1, end1, start2, end2)) {
            for (int i = std::min(start1, start2); i <= std::max(start1, start2); i++) {
                for (int j = std::min(end1, end2); j <= std::max(end1, end2); j++) {
                    arr[i][j] = ' ';
                }
            }
            big--;
        } else {
            std::cout << "Position of the ship is already filled. Try again" << std::endl;
        }
    }
    while (huge > 0) {
        std::cout << huge << " ships left" << std::endl;
        std::cout << "Input first coordinate of big ship:";
        std::cin >> start1 >> end1;
        std::cout << "Input second coordinate of big ship:";
        std::cin >> start2 >> end2;
        while (!CheckCoordinate(start1) || !CheckCoordinate(end1) || !CheckCoordinate(start2)
               || !CheckCoordinate(end2) || (abs(start1 - start2) > 0 && abs(end1 - end2) > 0)
               || abs(start1 - start2) != 4 || abs(end1 - end2) != 4) {
            std::cout << "Wrong input. Try again" << std::endl;
            std::cout << "Input first coordinate of small ship:";
            std::cin >> start1 >> end1;
            std::cout << "Input second coordinate of small ship:";
            std::cin >> start2 >> end2;
        }
        if (CheckLocation(arr, start1, end1, start2, end2)) {
            for (int i = std::min(start1, start2); i <= std::max(start1, start2); i++) {
                for (int j = std::min(end1, end2); j <= std::max(end1, end2); j++) {
                    arr[i][j] = ' ';
                }
            }
            huge--;
        } else {
            std::cout << "Position of the ship is already filled. Try again" << std::endl;
        }
    }
}

int InitField(int arr[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = '0';
        }
    }
    return arr[10][10];
}

int main() {
    int firstPlayer[10][10];
    int secondPlayer[10][10];
    int firstField[10][10];
    int secondField[10][10];

    //заполнить поля
    InitField(firstPlayer);
    InitField(secondPlayer);
    firstField[10][10] = firstPlayer[10][10];
    secondField[10][10] = secondPlayer[10][10];

    //расставить корабли
    std::cout << "Player 1, arrange your ships!" << std::endl;
    InstallShips(firstPlayer);
    std::cout << "First player finished" << std::endl;

    std::cout << "Player 2, arrange your ships!" << std::endl;
    InstallShips(secondPlayer);
    std::cout << "Second player finished" << std::endl;

    //выстрел1

    //проверка2

    //выстрел2

    //проверка1

    //инфо о победе

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
