#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>  // For getch() - Windows only

#define FILENAME "record.txt"

struct prisoner {
    char name[100];
    char gender[10];
    int age;
    int id;
    char crime[100];
};

void addPrisoner();
void viewPrisoners();
void searchPrisoner();
void deletePrisoner();
void login();

int main() {
    login();

    int choice;

    do {
        system("cls");
        printf("====== PRISON MANAGEMENT SYSTEM ======\n");
        printf("1. Add Prisoner\n");
        printf("2. View All Prisoners\n");
        printf("3. Search Prisoner\n");
        printf("4. Delete Prisoner\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPrisoner(); break;
            case 2: viewPrisoners(); break;
            case 3: searchPrisoner(); break;
            case 4: deletePrisoner(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }

        printf("\nPress any key to continue...");
        getch();
    } while (choice != 5);

    return 0;
}

void login() {
    char username[20], password[20];

    while (1) {
        system("cls");
        printf("Login to the system\n");
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "admin") == 0) {
            printf("Login successful.\n");
            break;
        } else {
            printf("Invalid credentials. Try again.\n");
            getch();
        }
    }
}

void addPrisoner() {
    FILE *fp = fopen(FILENAME, "a");
    if (!fp) {
        perror("Unable to open file");
        return;
    }

    struct prisoner p;
    printf("Enter Prisoner ID: ");
    scanf("%d", &p.id);
    printf("Enter Name: ");
    fflush(stdin);
    gets(p.name);
    printf("Enter Gender: ");
    gets(p.gender);
    printf("Enter Age: ");
    scanf("%d", &p.age);
    printf("Enter Crime: ");
    fflush(stdin);
    gets(p.crime);

    fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
    printf("Prisoner added successfully.\n");
}

void viewPrisoners() {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        perror("Unable to open file");
        return;
    }

    struct prisoner p;
    printf("=== List of Prisoners ===\n");

    while (fread(&p, sizeof(p), 1, fp)) {
        printf("\nID: %d\nName: %s\nGender: %s\nAge: %d\nCrime: %s\n",
               p.id, p.name, p.gender, p.age, p.crime);
    }

    fclose(fp);
}

void searchPrisoner() {
    FILE *fp = fopen(FILENAME, "r");
    if (!fp) {
        perror("Unable to open file");
        return;
    }

    int targetID;
    int found = 0;
    struct prisoner p;

    printf("Enter prisoner ID to search: ");
    scanf("%d", &targetID);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id == targetID) {
            printf("\nID: %d\nName: %s\nGender: %s\nAge: %d\nCrime: %s\n",
                   p.id, p.name, p.gender, p.age, p.crime);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Prisoner not found.\n");
    }

    fclose(fp);
}

void deletePrisoner() {
    FILE *fp = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) {
        perror("Unable to open file");
        return;
    }

    int targetID;
    int found = 0;
    struct prisoner p;

    printf("Enter prisoner ID to delete: ");
    scanf("%d", &targetID);

    while (fread(&p, sizeof(p), 1, fp)) {
        if (p.id != targetID) {
            fwrite(&p, sizeof(p), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found)
        printf("Prisoner deleted successfully.\n");
    else
        printf("Prisoner ID not found.\n");
}
