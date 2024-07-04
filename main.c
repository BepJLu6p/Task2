#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>

// Формули для списку без НСД я не знайшов, тож через нього
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
//Тут рахую НСК 2-х членів списку
int nsk2(int a, int b) {
    return (a / gcd(a, b)) * b;
}

//Тут рахую НСК списку всього
int lcm_of_list(int numbers[], int n) {
    int result = numbers[0];
    for (int i = 1; i < n; ++i) {
        result = nsk2(result, numbers[i]);
    }
    return result;
}

int main() {
    int n;
    printf("\nEnter count of numbers: ");
    scanf("%d", &n);

    if (n < 2 && n > 20) {
        printf("\nAl least more than 2 and less then 20\n");
        return 1;
    }

    int numbers[n];
    printf("\nEnter %d numbers cherez probil: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &numbers[i]);
    }

    // Знаходимо НСК
    int result_lcm = lcm_of_list(numbers, n);

    //Результат
    printf("\nNSK: %d\n", result_lcm);

    return 0;
}
