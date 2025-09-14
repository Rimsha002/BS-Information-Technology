#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 100

void addAccount(int accountNumbers[], double balances[], char accountHolders[][50], int *accountCount);
void searchAccount(int accountNumbers[], double balances[], char accountHolders[][50], int accountCount);
void displayAccounts(int accountNumbers[], double balances[], char accountHolders[][50], int accountCount);
void saveToFile(int accountNumbers[], double balances[], char accountHolders[][50], int accountCount);
void loadFromFile(int accountNumbers[], double balances[], char accountHolders[][50], int *accountCount);

int main() {
    int accountNumbers[MAX_ACCOUNTS];
    double balances[MAX_ACCOUNTS];
    char accountHolders[MAX_ACCOUNTS][50];
    int accountCount = 0, exit = 0;

    loadFromFile(accountNumbers, balances, accountHolders, &accountCount);

    while (exit == 0) {
        int choice;
        printf("\n--------------------------------\n");
        printf("1. Add Account\n");
        printf("2. Search Account\n");
        printf("3. Display Accounts\n");
        printf("4. Save and EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount(accountNumbers, balances, accountHolders, &accountCount);
                break;
            case 2:
                searchAccount(accountNumbers, balances, accountHolders, accountCount);
                break;
            case 3:
                displayAccounts(accountNumbers, balances, accountHolders, accountCount);
                break;
            case 4:
                saveToFile(accountNumbers, balances, accountHolders, accountCount);
                printf("\n----------PROGRAM SAVED AND ENDED---------\n");
                exit = 1;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void addAccount(int accountNumbers[], double balances[], char accountHolders[][50], int *accountCount) {
    int addMore = 1;
    while (addMore == 1 && *accountCount < MAX_ACCOUNTS) {
        int i = *accountCount;
        printf("Enter Account Number: ");
        scanf("%d", &accountNumbers[i]);
        printf("Enter Initial Balance: ");
        scanf("%lf", &balances[i]);
        printf("Enter Account Holder's Name: ");
        scanf("%s", accountHolders[i]);
        (*accountCount)++;
        printf("\nTo add more accounts, press (1) else press 0 key: ");
        scanf("%d", &addMore);
    }
}

void searchAccount(int accountNumbers[], double balances[], char accountHolders[][50], int accountCount) {
    int accountNumber;
    printf("\nEnter Account Number to search: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountCount; i++) {
        if (accountNumbers[i] == accountNumber) {
            printf("Account %d is registered to %s with a balance of %.2lf\n",
                   accountNumber, accountHolders[i], balances[i]);
            return;
        }
    }

    printf("Account %d is not found\n", accountNumber);
}

void displayAccounts(int accountNumbers[], double balances[], char accountHolders[][50], int accountCount) {
    int back = 0;
    while (back == 0) {
        printf("\n--------------------------------\n");
        printf("a. Account List\n");
        printf("b. Back\n");
        printf("\nEnter your choice: ");
        char choice;
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                if (accountCount == 0) {
                    printf("---NO ACCOUNTS TO DISPLAY---\n");
                } else {
                    printf("----Account List----\n");
                    for (int i = 0; i < accountCount; i++) {
                        printf("%d. Account %d: %s - Balance: %.2lf\n", i + 1,
                               accountNumbers[i], accountHolders[i], balances[i]);
                    }
                }
                break;
            case 'b':
                back = 1;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

void saveToFile(int accountNumbers[], double balances[], char accountHolders[][50], int accountCount) {
    FILE *file = fopen("bank_data.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    fprintf(file, "%d\n", accountCount);

    for (int i = 0; i < accountCount; i++) {
        fprintf(file, "%d %.2lf %s\n", accountNumbers[i], balances[i], accountHolders[i]);
    }

    fclose(file);
}

void loadFromFile(int accountNumbers[], double balances[], char accountHolders[][50], int *accountCount) {
    FILE *file = fopen("bank_data.txt", "r");
    if (file == NULL) {
        printf("File not found. Starting with an empty account set.\n");
        return;
    }

    fscanf(file, "%d", accountCount);

    for (int i = 0; i < *accountCount; i++) {
        fscanf(file, "%d %lf %s", &accountNumbers[i], &balances[i], accountHolders[i]);
    }

    fclose(file);
}