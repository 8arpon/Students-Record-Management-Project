#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define a struct Records

a{
    char ID[15];
    char Name[50];
    char Contact[15];
    int Age;
    char Section[10];

    a *link;
};

a *head = NULL;
void intro();
void aboutUs();
a *newStudent(a *head);
void showStudents(a *head);
void searchStudent(a *head);
void updateRecord(a *head);

int main(){
    printf("\n==================== EncoderZ ====================\n");
    printf("\nWelcome to the Student record management Project\n");
    printf("--------------------------------------------------\n\n");
    int check;
    do{
        intro();
        scanf("%d", &check);
        if(check == 6){
            aboutUs();
        }
        else if(check == 1){
            head = newStudent(head);
        }
        else if(check == 2){
            showStudents(head);
        }
        else if(check == 3){
            searchStudent(head);
        }
        else if(check == 4){
            updateRecord(head);
        }

    }while(check != 7);

    return 0;
}



void intro(){
    printf("\nPlease select an option:\n");
    printf("1. New Student\n");
    printf("2. View All Students' Records\n");
    printf("3. Search students info\n");
    printf("4. Update student info\n");
    printf("5. About us\n");
    printf("6. Exit\n\n");
}

void aboutUs(){
    printf("\n---------------------------------------------------------------\n");
    printf("\nDetails of our Team members: \n");
    printf("\n======================== EncoderZ ========================\n\n");
    printf("1. Arpon Sarker\n   Daffodil International University\n   ID: 242-15-964\n");
    printf("2. Abdul Jalil Tayef\n   Daffodil International University\n   ID: 242-15-648\n");
    printf("3. Md. Ikramul Islam Sami\n   Daffodil International University\n   ID: 242-15-591\n");
    printf("4. Shahriar Arefin\n   Daffodil International University\n   ID: 242-15-943\n");
    printf("---------------------------------------------------------------\n\n");
}

a *addNew(char tName[50], char tID[15], char tContact[15], char tSection[10], int tAge){
    a *tempNode = (a*) malloc(sizeof(a));

    strcpy(tempNode -> Name, tName);
    strcpy(tempNode -> ID, tID);
    strcpy(tempNode -> Contact, tContact);
    strcpy(tempNode -> Section, tSection);
    tempNode -> Age = tAge;
    
    tempNode -> link = NULL;
    return tempNode;
}

a *newStudent(a *head){
    printf("\n------------- Entry Zone of Students -------------\n");
    char stName[50], stID[15], stContact[15], stSection[10];
    int stAge;
    printf("Name: ");
    getchar();
    fgets(stName, sizeof(stName), stdin);
    stName[strcspn(stName, "\n")] = 0;

    printf("ID: ");
    fgets(stID, sizeof(stID), stdin);
    stID[strcspn(stID, "\n")] = 0;

    printf("Section: ");
    fgets(stSection, sizeof(stSection), stdin);
    stSection[strcspn(stSection, "\n")] = 0;

    printf("Age: ");
    scanf("%d", &stAge);

    getchar();
    printf("Contact: ");
    fgets(stContact, sizeof(stContact), stdin);
    stContact[strcspn(stContact, "\n")] = 0;

    printf("\n>> Student Record added successfully...\n");

    if(head == NULL){
        return addNew(stName, stID, stContact, stSection, stAge);
    }
    a *tempNode = head;
    while(tempNode -> link != NULL){
        tempNode = tempNode -> link;
    }

    a *newNode = (a*) malloc(sizeof(a));
    strcpy(newNode -> Name, stName);
    strcpy(newNode -> ID, stID);
    strcpy(newNode -> Contact, stContact);
    strcpy(newNode -> Section, stSection);
    newNode -> Age = stAge;

    newNode -> link = NULL;
    tempNode -> link = newNode;
    return head;
}

void showStudents(a *head){
    if (head == NULL) {
        printf("\nThere is No students to display.\n");
        return;
    }
    printf("\n\n-------------- Students Records --------------\n");
    while(head != NULL){
        printf("----------------------------------------------\n");
        printf("Name: %s\n", head -> Name);
        printf("ID: %s\n", head -> ID);
        printf("Section: %s\n", head -> Section);
        printf("Age: %d\n", head -> Age);
        printf("Contact: %s\n", head -> Contact);
        printf("----------------------------------------------\n");
        head = head -> link;
    }
    printf("\n");
}

void searchStudent(a *head){
    char ID[15];
    printf("Enter the ID: ");
    getchar();
    fgets(ID, sizeof(ID), stdin);
    ID[strcspn(ID, "\n")] = 0;
    int count = 0;
    while(head != NULL){
        if(strcmp(ID, head -> ID) == 0){
            count = 1;
            break;
        }
        head = head -> link;
    }
    if(count == 1){
        printf("\nRecord Found...\n");
        printf("----------------------------------------------\n");
        printf("Name: %s\n", head -> Name);
        printf("ID: %s\n", head -> ID);
        printf("Section: %s\n", head -> Section);
        printf("Age: %d\n", head -> Age);
        printf("Contact: %s\n", head -> Contact);
        printf("----------------------------------------------\n");
    }
    else{
        printf("There is no student with the ID.\n");
    }
}

void updateRecord(a *head){
    char ID[15];
    printf("Enter the ID (You want to update): ");
    getchar();
    fgets(ID, sizeof(ID), stdin);
    ID[strcspn(ID, "\n")] = 0;
    int count = 0;
    while(head != NULL){
        if(strcmp(ID, head -> ID) == 0){
            printf("What do you want to update: ");
            printf("\n1. Name\n2. ID\n3. Section\n4. Age\n5. Contact\n");
            int choice;
            scanf("%d", &choice);
            if(choice == 1){
                printf("Enter the Name(To upgrade): ");
                char uName[50];
                getchar();
                fgets(uName, sizeof(uName), stdin);
                uName[strcspn(uName, "\n")] = 0;
                strcpy(head -> Name, uName);
            }
            else if(choice == 2){
                printf("Enter the ID(To upgrade): ");
                char uID[15];
                getchar();
                fgets(uID, sizeof(uID), stdin);
                uID[strcspn(uID, "\n")] = 0;
                strcpy(head -> ID, uID);
            }
            else if(choice == 3){
                printf("Enter the Section(To upgrade): ");
                char uSection[10];
                getchar();
                fgets(uSection, sizeof(uSection), stdin);
                uSection[strcspn(uSection, "\n")] = 0;
                strcpy(head -> Section, uSection);
            }
            else if(choice == 4){
                printf("Enter the Age(To upgrade): ");
                int uAge;
                head -> Age = uAge;
            }
            else if(choice == 5){
                printf("Enter the Contact(To upgrade): ");
                char uContact[15];
                getchar();
                fgets(uContact, sizeof(uContact), stdin);
                uContact[strcspn(uContact, "\n")] = 0;
                strcpy(head -> Contact, uContact);
            }
            printf("\nRecord has been updated successfully...\n");
            count = 1;
            
        }
        head = head -> link;
    }
    if(count == 0){
        printf("\nNo Record found to update...\n");
    }
}
