#include <stdio.h>

struct Household {
    int id;
    float income;
    int members;
};

float averageIncome(struct Household h[], int n) {
    float sum = 0;
    for (int i = 0; i < n; i++)
        sum += h[i].income;
    return sum / n;
}

void printAboveAverage(struct Household h[], int n, float avg) {
    for (int i = 0; i < n; i++) {
        if (h[i].income > avg)
            printf("ID: %d, Income: %.2f\n", h[i].id, h[i].income);
    }
}

void sortByMembers(struct Household h[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (h[i].members > h[j].members) {
                struct Household temp = h[i];
                h[i] = h[j];
                h[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of households: ");
    scanf("%d", &n);
    struct Household h[10];
    for (int i = 0; i < n; i++) {
        printf("Enter ID, Income, Members for household %d: ", i + 1);
        scanf("%d %f %d", &h[i].id, &h[i].income, &h[i].members);
    }
    float avg = averageIncome(h, n);
    printf("\nAverage Income: %.2f\n", avg);
    printf("Households with income above average:\n");
    printAboveAverage(h, n, avg);
    sortByMembers(h, n);
    printf("\nSorted by family members:\n");
    for (int i = 0; i < n; i++)
        printf("ID: %d, Income: %.2f, Members: %d\n", h[i].id, h[i].income, h[i].members);
    return 0;
}
