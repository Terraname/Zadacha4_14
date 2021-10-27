// Zadacha14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    int n, m;
    std::cout << "Enter N\n";
    std::cin >> n;
    while (std::cin.fail() || n <= 0)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Wrong N!\n";
        std::cout << "Enter N another time\n";
        std::cin >> n;
    }
    std::cout << "Enter M\n";
    std::cin >> m;
    while (std::cin.fail() || m <= 0)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "Wrong M!\n";
        std::cout << "Enter M another time\n";
        std::cin >> m;
    }
    char** array;
    //char** array = new char* [n+2];
    array = (char**)malloc((n + 2) * (m + 2) * sizeof(char));
    for (int i = 0; i < n + 2; i++)
    {
        //array[i] = new char[m+2];
        array[i] = (char*)malloc((m + 2) * sizeof(char));
    }

    std::cout << "Enter elements of the field\n";
    for (int i = 0; i <= n + 1; i += n+1)
    {
        array[i][0] = 0;
        array[i][m+1] = 0;
    }
    for (int j = 0; j <= m + 1; j += m+1)
    {
        array[0][j] = 0;
        array[n+1][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> array[i][j];
            // 42 - * , 46 - .
            while (std::cin.fail() || (array[i][j] != 42 && array[i][j] != 46))
            {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                std::cout << "Wrong element's value!\n";
                std::cout << "Enter element № " << (i + 1) << ", " << (j + 1) << "  of the array another time\n";
                std::cin >> array[i][j];
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (array[i][j] == 46)
            {
                char temp = 0;
                for (int k = i - 1; k <= i + 1; k++)
                {
                    for (int t = j - 1; t <= j + 1; t++)
                    {
                        if (array[k][t] == 42)
                        {
                            temp++;
                        }
                    }
                }
                if (temp == 0)
                {
                    array[i][j] = 32;
                }
                else
                {
                    array[i][j] = temp + 48;
                }
            }
        }
    }
    std::cout << "\n";
    std::cout << "The new field is: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cout << array[i][j];
        }
        std::cout << "\n";
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
