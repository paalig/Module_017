#include <iostream>
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
bool CheckLocation(char field[10][10], int start1, int end1, int start2, int end2) {
    for (int i = std::min(start1, start2); i <= std::max(start1, start2); i++) {
        for (int j = std::min(end1, end2); j <= std::max(end1, end2); j++) {
            if (field[i][j] == '@') {
                return false;
            }
        }
    }
    return true;
}

bool CheckLocationTiny(char field[10][10], int start1, int end1) {
    return (field[start1][end1] != '@');
}

bool CheckCoordinate(int a) {
    return (a >= 0 && a <= 9);
}

void Arrange(char arr[10][10], int count, std::string type, int length) {
    int start1, end1, start2, end2;

    while (count > 0) {
        std::cout << count << " ships left" << std::endl;
        std::cout << "Input first coordinate of " << type << " ship:";
        std::cin >> start1 >> end1;
        std::cout << "Input second coordinate of " << type << " ship:";
        std::cin >> start2 >> end2;
        while (!CheckCoordinate(start1) || !CheckCoordinate(end1) || !CheckCoordinate(start2)
               || !CheckCoordinate(end2) || (abs(start1 - start2) > 0 && abs(end1 - end2) > 0)
               || (abs(start1 - start2) != (length - 1) && abs(end1 - end2) != (length - 1))) {
            std::cout << "Wrong coordinate input. Try again" << std::endl;
            std::cout << "Input first coordinate of " << type << " ship:";
            std::cin >> start1 >> end1;
            std::cout << "Input second coordinate of " << type << " ship:";
            std::cin >> start2 >> end2;
        }
        if (CheckLocation(arr, start1, end1, start2, end2)) {
            for (int i = std::min(start1, start2); i <= std::max(start1, start2); i++) {
                for (int j = std::min(end1, end2); j <= std::max(end1, end2); j++) {
                    arr[i][j] = '@';
                }
            }
            count--;
        } else {
            std::cout << "Position of the ship is already filled. Try again" << std::endl;
        }
    }
}

void InstallShips(char arr[10][10]) {

    int tinyCount = 4;
    int smallCount = 3;
    int bigCount = 2;
    int hugeCount = 1;

    int start1, end1;
    std::cout << "Install tiny ships:" << std::endl;
    while (tinyCount > 0) {
        std::cout << tinyCount << " ships left" << std::endl;
        std::cout << "Input coordinate of tiny ship:";
        std::cin >> start1 >> end1;
        while (!CheckCoordinate(start1) || !CheckCoordinate(end1)) {
            std::cout << "Wrong coordinate input. Try again";
            std::cin >> start1 >> end1;
        }
        if (CheckLocationTiny(arr, start1, end1)) {
            arr[start1][end1] = '@';
            tinyCount--;
        } else {
            std::cout << "Position of the ship is already filled. Try again" << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "Install small ships:" << std::endl;
    Arrange(arr, smallCount, "small", 2);
    std::cout << std::endl;
    std::cout << "Install big ships:" << std::endl;
    Arrange(arr, bigCount, "big", 3);
    std::cout << std::endl;
    std::cout << "Install huge ships:" << std::endl;
    Arrange(arr, hugeCount, "huge", 4);
    std::cout << std::endl;
}

void InitField(char arr[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = '0';
        }
    }
}

bool CheckWin(char arr[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] == '@') {
                return true;
            }
        }
    }
    return false;
}

bool Shot(char arr[10][10], int a, int b) {
    return (arr[a][b] == '@' || arr[a][b] == ' ');
}

std::string ChangePlayer(std::string player) {
    if (player == "Player 1") {
        player = "Player 2";
    } else {
        player = "Player 1";
    }
    return player;
}

void PrintField(char arr[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] == '@') {
                std::cout << '0';
            } else {
                std::cout << arr[i][j];
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    char firstPlayer[10][10];
    char secondPlayer[10][10];

    InitField(firstPlayer);
    InitField(secondPlayer);

    std::cout << "Player 1:" << std::endl;
    InstallShips(firstPlayer);
    std::cout << "First player finished" << std::endl;
    std::cout << std::endl;

    std::cout << "Player 2:" << std::endl;
    InstallShips(secondPlayer);
    std::cout << "Second player finished" << std::endl;
    std::cout << std::endl;

    std::string currentPlayer = "Player 1";
    while (CheckWin(firstPlayer) && CheckWin(secondPlayer)) {
        int a, b;
        std::cout << currentPlayer << std::endl;
        std::cout << "Make your shot!";
        std::cin >> a >> b;
        while (!CheckCoordinate(a) || !CheckCoordinate(b)) {
            std::cout << "Wrong coordinate. Try again";
            std::cin >> a >> b;
        }
        if (currentPlayer == "Player 1") {
            if (Shot(secondPlayer, a, b)) {
                secondPlayer[a][b] = ' ';
                std::cout << "Damage!" << std::endl;
            } else {
                secondPlayer[a][b] = '*';
                std::cout << "Miss!" << std::endl;
            }
            PrintField(secondPlayer);
            std::cout << std::endl;
        } else {
            if (Shot(firstPlayer, a, b)) {
                firstPlayer[a][b] = ' ';
                std::cout << "Damage!" << std::endl;
            } else {
                firstPlayer[a][b] = '*';
                std::cout << "Miss!" << std::endl;
            }
            PrintField(firstPlayer);
            std::cout << std::endl;
        }
        currentPlayer = ChangePlayer(currentPlayer);
    }
    currentPlayer = ChangePlayer(currentPlayer);
    std::cout << currentPlayer << " won!" << std::endl;
}
