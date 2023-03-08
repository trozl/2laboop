#include <iostream>
#include <locale>
#include <cstdlib>
#include <ctime>

using namespace std;

#define min -100
#define max 100

void sort(int* arr, int size) {
    int temp; // временная переменная для обмена элементов местами

    // Сортировка массива пузырьком
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // меняем элементы местами
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, minimum, minel, sum, switchstate;
    sum = 0;
    srand(time(NULL));
    setlocale(LC_ALL, "RUS");
    printf("Выберете номер задания\n1 Задание: Работа с одномерным массивом\n2 Задание: Работа с двухмерным массивом\n");
    cin >> switchstate;
    switch (switchstate) {
    case 1: {
        printf("Введите колличество элементов одномерного массива, которые необходимо заполнить\n");
        cin >> n;
        int* arr = new int[n];
        minimum = min;
        for (int i = 0; i < n; i++) {
            arr[i] = minimum + rand() % (max - min + 1);
        }
        for (int i = 0; i < n; i++) {
            printf("%d\t", arr[i]);
        }
        minel = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] < minel) {
                minel = arr[i];
            }
        }
        printf("\nМинимальный элемент массива равен %d", minel);
        for (int i = 0; i < n; i++) {
            sum = sum + arr[i];
        }
        printf("\nСумма всех эдементов массива равна %d\n", sum);
        printf("Только положительные элементы массива:");
        for (int i = 0; i < n; i++) {
            if (arr[i] > 0) {
                printf(" %d ", arr[i]);
            }
        }
        printf("\nСортировка массива методом простого обмена от меньшего к большему:\n");
        sort(arr, n);
        for (int i = 0; i < n; i++) {
            printf("%d\t", arr[i]);
        }
    }
          break;
    case 2: {
        int array6x5[6][5];
        printf("Введите элементы массива построчно\n");
        for (int i = 0; i < 6; i++) {
            if (i != 0) {
                printf("Переход на новую строку\n");
            }
            for (int j = 0; j < 5; j++) {
                cin >> array6x5[i][j];
            }
        }
        printf("Массив заполнен\n");
        for (int i = 0; i < 6; i++) {
            printf("\n");
            for (int j = 0; j < 5; j++) {
                printf("\t%d\t ", array6x5[i][j]);
            }
        }
        int otvarr[5];
        for (int j = 0; j < 5; j++) {
            int stolbcounter = 0;
            int counter = 0;
            for (int i = 0; i < 6; i++) {
                if (array6x5[i][j] % 2 == 0 && counter == 0 && array6x5[i][j] != 0) {
                    otvarr[j] = array6x5[i][j];
                    counter = 1;
                }
                else  stolbcounter++;
                if (stolbcounter == 6) otvarr[j] = 0;
            }
        }
        printf("\nСписок первых четных элементов каждого\n");
        for (int i = 0; i < 5; i++) {
            printf("%d ", otvarr[i]);
        }
    }
          break;
    }
}


