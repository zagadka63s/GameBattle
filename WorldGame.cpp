#include <iostream> // Библиотека для ввода-вывода
#include <ctime> // Эти две библиотеки нуждны для работы с временем и генераций случайных чисел
#include <cstdlib>

using namespace std; // Для упрощения кода 

int attackMonster(int playerLevel) { // Функция, которая генерирует случайный урон игрока при атаке монста
    return rand() % playerLevel + 1;
}

int main() {

    setlocale(LC_ALL, "russian");
    srand(time(0)); // Для инициализации генератора случайных чисел на основе текущего времени

    string playerName; // Стринговая переменная для имени персонажа
    cout << "Добро пожаловать в улучшенную ролевую игру!" << endl;
    cout << "Введите имя персонажа: ";
    cin >> playerName;

    // Инициализация параметров игрока 
    int playerLevel = 1; // Инициализация уровня
    int playerHealth = 100; // Инициализация здоровья игрока
    int monsterHealth = 0;

    cout << "Привет, " << playerName << "! Вы - уровень " << playerLevel << " персонаж." << endl;
    cout << "У вас " << playerHealth << " здоровья." << endl;

    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') { // Цикл для выбора продолжения игры
        monsterHealth = rand() % 70 + 30; // Создание случайного здоровья для монста 
        cout << "На вас напал монстр с " << monsterHealth << " здоровья!" << endl;

        while (playerHealth > 0 && monsterHealth > 0) {
            cout << "Выберите действие:" << endl;
            cout << "1. Атаковать" << endl;
            cout << "2. Использовать зелье лечения" << endl;

            int choice;
            cin >> choice;

            if (choice == 1) {
                int playerAttack = attackMonster(playerLevel);
                int monsterAttack = rand() % 10 + 1;

                cout << "Вы атакуете монстра и наносите " << playerAttack << " урона." << endl;
                monsterHealth -= playerAttack;

                if (monsterHealth <= 0) {
                    cout << "Монстр побежден!" << endl;
                    break;
                }

                cout << "Монстр атакует вас и наносит " << monsterAttack << " урона." << endl;
                playerHealth -= monsterAttack;

                if (playerHealth <= 0) {
                    cout << "Вы погибли!" << endl;
                    break;
                }
            }
            else if (choice == 2) {
                int healingPotion = rand() % 20 + 10;
                cout << "Вы использовали зелье лечения и восстановили " << healingPotion << " здоровья." << endl;
                playerHealth += healingPotion;
                if (playerHealth > 100) {
                    playerHealth = 100;
                }
            }
            else {
                cout << "Неверный выбор! Попробуйте снова." << endl;
            }
        }

        cout << "Хотите сыграть еще? (y/n): ";
        cin >> playAgain;
    }

    cout << "Спасибо за игру, до свидания!" << endl;

    return 0;
}
