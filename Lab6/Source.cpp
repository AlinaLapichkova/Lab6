#include <iostream>
#include <Windows.h>
#include <fstream>
using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int n, c;
    c = 0;
    while (c == 0) {
        cout << " Выберите действие:\n 1 - Random\n 2 - File\n 3 - Exit\n Ваш выбор: ";
        cin >> c;
        while (c < 1 || c > 3) {
            cout << "\n Вы ввели некорректные данные.\n Введите целое число от 1 до 3 : ";
            cin >> c;
        }
        if (c == 1) {
            cout << "Введите кол-во элементов n = ";
            cin >> n;

            int** a = new int* [n];
            for (int i = 0; i < n; i++)
            {
                a[i] = new int[n];
                for (int j = 0; j < n; j++)
                {
                    a[i][j] = 10 + rand() % 300;
                }
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << a[i][j] << "  ";
                }
                cout << endl;
            }
            int max = a[0][1];
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (max < a[i][j])
                        max = a[i][j];

                }
            }
            int min = a[0][1];
            for (int i = n - 1; i >= 1; --i) {
                for (int j = i - 1; j >= 0; --j) {
                    if (min > a[i][j])
                        min = a[i][j];
                }
            }

            cout << "\nMax " << max << endl;
            cout << "Min " << min << endl;
            for (int i = 0; i < n; i++)
            {
                delete[] a[i];
            }
            delete[] a;
            system("pause");
            c = 0;
        }
        if (c == 2) {
            int n; // к-во строк
            ifstream file("Текст.txt");
            string str;
            n = 6;
            int** a = new int* [n];
            if (!file) {
                return 1;
            }
            else {
                for (int i = 0; i < n; i++) // цикл заполнения матрицы
                {
                    a[i] = new int[n];
                    for (int j = 0; j < n; j++)
                    {
                        file >> a[i][j];
                    }
                }
            }
            file.close();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << a[i][j] << "  ";
                }
                cout << endl;
            }
            int max = a[0][1];
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (max < a[i][j])
                        max = a[i][j];

                }
            }
            int min = a[0][1];
            for (int i = n - 1; i >= 1; --i) {
                for (int j = i - 1; j >= 0; --j) {
                    if (min > a[i][j])
                        min = a[i][j];
                }
            }

            cout << "\nMax " << max << endl;
            cout << "Min " << min << endl;
            for (int i = 0; i < n; i++)
            {
                delete[] a[i];
            }
            delete[] a;
            system("pause");
            c = 0;
        }
        if (c == 3) {
            return 0;
        }
    }
}
