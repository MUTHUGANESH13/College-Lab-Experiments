#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Phonebook_Contacts {
    char FirstName[20];
    char LastName[20];
    char PhoneNumber[20];
} phone;

void AddEntry(phone *phonebook);
void DeleteEntry(phone *phonebook);
void PrintEntry(phone *phonebook);
void SearchForNumber(phone *phonebook);

int counter = 0;
char FileName[256];
FILE *pRead;
FILE *pWrite;

int main(void) {
    phone *phonebook;
    phonebook = (phone*) malloc(sizeof(phone) * 100);
    int iSelection = 0;

    if (phonebook == NULL) {
        printf("Out of Memory. The program will now exit\n");
        return 1;
    }

    do {
        printf("\n\t\t\tPhonebook Menu");
        printf("\n\n\t(1)\tAdd Friend");
        printf("\n\t(2)\tDelete Friend");
        printf("\n\t(3)\tDisplay Phonebook Entries");
        printf("\n\t(4)\tSearch for Phone Number");
        printf("\n\t(5)\tExit Phonebook");
        printf("\n\nWhat would you like to do? ");
        scanf("%d", &iSelection);

        switch (iSelection) {
            case 1:
                AddEntry(phonebook);
                break;
            case 2:
                DeleteEntry(phonebook);
                break;
            case 3:
                PrintEntry(phonebook);
                break;
            case 4:
                SearchForNumber(phonebook);
                break;
            case 5:
                printf("\nYou have chosen to exit the Phonebook.\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    } while (iSelection != 5);

    free(phonebook);
    return 0;
}

void AddEntry(phone *phonebook) {
    pWrite = fopen("phonebook_contacts.dat", "a");
    if (pWrite == NULL) {
        perror("The following error occurred");
        exit(EXIT_FAILURE);
    }

    counter++;
    printf("\nFirst Name: ");
    scanf("%s", phonebook[counter - 1].FirstName);
    printf("Last Name: ");
    scanf("%s", phonebook[counter - 1].LastName);
    printf("Phone Number (XXX-XXX-XXXX): ");
    scanf("%s", phonebook[counter - 1].PhoneNumber);

    printf("\n\tFriend successfully added to Phonebook\n");
    fprintf(pWrite, "%s\t%s\t%s\n", phonebook[counter - 1].FirstName, phonebook[counter - 1].LastName, phonebook[counter - 1].PhoneNumber);
    fclose(pWrite);
}

void DeleteEntry(phone *phonebook) {
    int x = 0;
    char deleteFirstName[20], deleteLastName[20];

    printf("\nFirst name: ");
    scanf("%s", deleteFirstName);
    printf("Last name: ");
    scanf("%s", deleteLastName);

    for (x = 0; x < counter; x++) {
        if (strcmp(deleteFirstName, phonebook[x].FirstName) == 0 && strcmp(deleteLastName, phonebook[x].LastName) == 0) {
            for (int i = x; i < counter - 1; i++) {
                phonebook[i] = phonebook[i + 1];
            }
            printf("Record deleted from the phonebook.\n\n");
            --counter;
            return;
        }
    }
    printf("That contact was not found, please try again.\n");
}

void PrintEntry(phone *phonebook) {
    printf("\nPhonebook Entries:\n\n");
    pRead = fopen("phonebook_contacts.dat", "r");
    if (pRead == NULL) {
        perror("The following error occurred");
        exit(EXIT_FAILURE);
    }

    for (int x = 0; x < counter; x++) {
        printf("\n(%d)\n", x + 1);
        printf("Name: %s %s\n", phonebook[x].FirstName, phonebook[x].LastName);
        printf("Number: %s\n", phonebook[x].PhoneNumber);
    }
    fclose(pRead);
}

void SearchForNumber(phone *phonebook) {
    char TempFirstName[20], TempLastName[20];
    printf("\nPlease type the name of the friend you wish to find a number for.");
    printf("\n\nFirst Name: ");
    scanf("%s", TempFirstName);
    printf("Last Name: ");
    scanf("%s", TempLastName);

    for (int x = 0; x < counter; x++) {
        if (strcmp(TempFirstName, phonebook[x].FirstName) == 0 && strcmp(TempLastName, phonebook[x].LastName) == 0) {
            printf("\n%s %s's phone number is %s\n", phonebook[x].FirstName, phonebook[x].LastName, phonebook[x].PhoneNumber);
            return;
        }
    }
    printf("Contact not found.\n");
}
