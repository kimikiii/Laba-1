
#include <iostream>
#include <windows.h>

using namespace std;

// 32 для инт и флоат 5 задание
unsigned int modifyBit(unsigned int val, int k, int op) {
    unsigned int mask = 1;
    if (op == 1) {
        val |= (mask << k);
    }
    else if (op == 2) {
        val &= ~(mask << k); 
    }
    else if (op == 3) {
        val ^= (mask << k);
    }

    return val;
}

// 64 для дабл 5 задание
unsigned long long modifyBit64(unsigned long long val, int k, int op)
{
    unsigned long long mask = 1;

    if (op == 1) {
        val |= (mask << k);
    }
    else if (op == 2) {
        val &= ~(mask << k); 
    }
    else if (op == 3) {
        val ^= (mask << k);
    }

    return val;
}

int main()
{
    // русский язык
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // 1 задание
    cout << "bool: " << sizeof(bool) << " байт - логический тип True/False" << endl;
    cout << "char: " << sizeof(char) << " байт - символьный тип" << endl;
    cout << "short int: " << sizeof(short int) << " байта - целое со знаком, -32768 до 32767" << endl;
    cout << "int: " << sizeof(int) << " байта - целое 32 бита"<< endl;
    cout << "long int: " << sizeof(long int) << "байта - длиное целое" << endl;
    //    cout << "long long int: " << sizeof(long long int) << endl;
    cout << "float: " << sizeof(float) << " байта - число с точкой, точность 6-7 знаков, 32 бита, быстрее всего" << endl;
    cout << "double: " << sizeof(double) << " байт - число с точкой, точность 15-16 знаков, 64 бита, быстро" << endl;
    cout << "long double: " << sizeof(long double) << " байт - число с точкой, расширенная точность" << endl;
    cout << endl;


    // 2 задание
    int a;
    cout << "Введите целое число: ";
    cin >> a;

    const int orderInt = sizeof(int) * 8;
    unsigned int maskI = 1 << (orderInt - 1);
    for (int i = 0; i < orderInt; i++) {
        if (a & (maskI >> i)) {
            cout << '1';
        }
        else {
            cout << '0';
        }
        if (i == 0) {
            cout << " ";
        } else if (i == 7 || i == 15 || i == 23) { 
            cout << " ";
        }
    }
    cout << endl;


    // 3 задание
    float f;
    cout << "Введите число float: ";
    cin >> f;

    unsigned int b = *(unsigned int *)&f;
    const int orderFloat = sizeof(float) * 8;
    unsigned int maskF = 1 << (orderFloat - 1);

    for (int i = 0; i < orderFloat; i++) {
        if (b & (maskF >> i)) {
            cout << '1';
        }
        else {
            cout << '0';
        }
        if (i == 0 || i == 8) {
            cout << " ";
        }
    }
    cout << endl;


    // 4 задание
    double d;
    cout << "Введите число double: ";
    cin >> d;

    unsigned long long c = *(unsigned long long *)&d;

    const int orderDouble = sizeof(double) * 8;

    unsigned long long maskD = (unsigned long long)1 << (orderDouble - 1);

    for (int i = 0; i < orderDouble; i++) {
        if (c & (maskD >> i)) {
            cout << '1';
        }
        else {
            cout << '0';
        }
        if (i == 0 || i == 11) {
            cout << " ";
        }
    }

    cout << endl;


// 5 задание
    int choice;

    while (true) {
        cout << "Выберите тип данных:" << endl;
        cout << "1. int" << endl;
        cout << "2. float" << endl;
        cout << "3. double" << endl;
        cout << "0. Выход из программы" << endl;
        cout << "Выбор: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Вводите только цифры пунктов меню!" << endl;
            continue;
        }

        if (choice == 0) {
            cout << "Выход" << endl;
            break;
        }



// инт
        if (choice == 1) {
            int a;
            int k, op;

            cout << "Введите целое число: ";
            cin >> a;

            if (cin.fail() || cin.peek() == '.') {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "[Ошибка] Вы выбрали int, но ввели дробное число или буквы!" << endl;
                continue;
            }

            cout << "Номер бита для изменения (0-31): ";
            cin >> k;

            if (cin.fail() || k < 0 || k > 31) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "[Ошибка] Для int номер бита должен быть от 0 до 31!" << endl;
                continue;
            }



            cout << "Действие (1 - установить в 1, 2 - сбросить в 0, 3 - инвертировать): ";
            cin >> op;

            if (cin.fail() || op < 1 || op > 3) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "[Ошибка] Выберите действие 1, 2 или 3!" << endl;
                continue;
            }

            a = (int)modifyBit((unsigned int)a, k, op);

            cout << "Результат (число):  " << a << endl;

        }

// флоат
        else if (choice == 2) {
            float f;
            int k, op;

            cout << "Введите дробное число (float): ";
            cin >> f;


            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "[Ошибка] Число должно быть дробным (с остатком после запятой)!" << endl;
                continue;
            }

            unsigned int bits = *(unsigned int *)&f;

            cout << "Номер бита для изменения (0-31): ";
            cin >> k;

            if (cin.fail() || k < 0 || k > 31) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "[Ошибка] Некорректный ввод числа!" << endl;
                continue;
            }

            cout << "Действие (1 - установить в 1, 2 - сбросить в 0, 3 - инвертировать): ";
            cin >> op;

            if (cin.fail() || op < 1 || op > 3) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "[Ошибка] Выберите действие 1, 2 или 3!" << endl;
                continue;
            }

            bits = modifyBit(bits, k, op);
            f = *(float*)&bits;

            cout << "Результат:  " << f << endl;
        }

// дабл
        else if (choice == 3) {
            double d;
            int k, op;

            cout << "Введите число (double): ";
            cin >> d;


        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "[Ошибка] Некорректный ввод числа!" << endl;
            continue; 
        }

            unsigned long long bits = *(unsigned long long *)&d;

            cout << "Номер бита для изменения (0-63): ";
            cin >> k;

            if (cin.fail() || k < 0 || k > 63) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "[Ошибка] Для double номер бита должен быть от 0 до 63!" << endl;
                continue;
            }


            cout << "Действие (1 - установить в 1, 2 - сбросить в 0, 3 - инвертировать): ";
            cin >> op;

            if (cin.fail() || op < 1 || op > 3) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "[Ошибка] Выберите действие 1, 2 или 3!" << endl;
                continue;
            }

            bits = modifyBit64(bits, k, op);
            d = *(double *)&bits;

            cout << "Результат (число):  " << d << endl;
        }

        else {
            cout << "Такого пункта нет, попробуйте снова!"
                 << endl;
        }
    }


    // индивидуальное задание Проверка чётности. Установить младший бит в 0 (округление вниз до чётного).
    double number;
    long long intNum;

    while (true) {
        cout << "Введите число: ";

        if (!(cin >> number)) {
            cout << "[Ошибка] Введено не число! Попробуйте еще раз." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;  
        }


        if (number != (long long)number) {
            cout << "[Ошибка] У числа есть дробная часть! Нужно целое (или вида X.0). Попробуйте еще раз." << endl;
            continue;
        }

        intNum = (long long)number;
        break;
    }

    if (intNum & 1) {
        cout << "Число нечётное" << endl;
    } else {
        cout << "Число чётное" << endl;
    }

    long long evenNum = intNum & ~1;
    cout << "После установки младшего бита в 0: " << evenNum << endl;
    return 0;
}
