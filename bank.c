#include <stdio.h>
#include <string.h>

struct Customer {
    int accNo;
    char name[50];
    float balance;
};

void printBelow5000(struct Customer c[], int n) {
    for (int i = 0; i < n; i++) {
        if (c[i].balance < 5000)
            printf("Account: %d, Name: %s\n", c[i].accNo, c[i].name);
    }
}

void sortByBalance(struct Customer c[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (c[i].balance > c[j].balance) {
                struct Customer temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of customers: ");
    scanf("%d", &n);
    struct Customer c[20];
    for (int i = 0; i < n; i++) {
        printf("Enter Account No, Name, Balance for customer %d: ", i + 1);
        scanf("%d %s %f", &c[i].accNo, c[i].name, &c[i].balance);
    }

    printf("\nCustomers with balance below 5000:\n");
    printBelow5000(c, n);

    sortByBalance(c, n);
    
    printf("\nSorted by balance:\n");
    for (int i = 0; i < n; i++)
        printf("Account: %d, Name: %s, Balance: %.2f\n", c[i].accNo, c[i].name, c[i].balance);
    return 0;
}
