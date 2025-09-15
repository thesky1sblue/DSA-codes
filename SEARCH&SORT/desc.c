#include <stdio.h>
#include <string.h>

#define MAX 100
#define NAME_LEN 50

void sortDescending(char names[][NAME_LEN], int n) {
    char temp[NAME_LEN];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) < 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

int binarySearch(char names[][NAME_LEN], int low, int high, char key[]) {
    if (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(names[mid], key);
        if (cmp == 0)
            return mid;
        else if (cmp < 0)
            return binarySearch(names, low, mid - 1, key);
        else
            return binarySearch(names, mid + 1, high, key);
    }
    return -1;
}

int main() {
    int n;
    char names[MAX][NAME_LEN];
    char key[NAME_LEN];

    printf("Enter number of names: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        fgets(names[i], NAME_LEN, stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    sortDescending(names, n);

    printf("\nNames in descending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    printf("\nEnter name to search: ");
    fgets(key, NAME_LEN, stdin);
    key[strcspn(key, "\n")] = '\0';

    int result = binarySearch(names, 0, n - 1, key);
    if (result != -1)
        printf("Name found at position %d.\n", result + 1);
    else
        printf("Name not found.\n");

    return 0;
}
