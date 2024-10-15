#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;


static void create(int* arr, int SIZE, int MIN, int MAX, int i)
{
    if (i < SIZE)
    {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
        create(arr, SIZE, MIN, MAX, i + 1);
    }
}


static void Print(int* arr, const int SIZE, int i)
{
    cout << setw(4) << arr[i];
    if (i < SIZE - 1)
        Print(arr, SIZE, i + 1);
    else
        cout << endl;
}


static void FindMinMaxIndexes(int* arr, int SIZE, int i, int& minIndex, int& maxIndex)
{
    if (i < SIZE)
    {
        if (arr[i] < arr[minIndex])
            minIndex = i;
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
        FindMinMaxIndexes(arr, SIZE, i + 1, minIndex, maxIndex);
    }
}


static double FindAverageOfMinMaxIndexes(int* arr, int SIZE)
{
    int minIndex = 0, maxIndex = 0;
    FindMinMaxIndexes(arr, SIZE, 1, minIndex, maxIndex); 

    return (minIndex + maxIndex) / 2.0;
}

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 10;
    int MIN = -10;
    int MAX = 10;

    int* arr = new int[SIZE];
    create(arr, SIZE, MIN, MAX, 0);  

    Print(arr, SIZE, 0); 
    cout << "\n\n";

    
    cout << "Середнє арифметичне індексів мінімального і максимального елементів: "
        << FindAverageOfMinMaxIndexes(arr, SIZE) << endl;

    delete[] arr;

    return 0;
}
