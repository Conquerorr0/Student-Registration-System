#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

const char *filename = "Ogrenciler.txt";

typedef struct Student {
    int number;
    char name[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    struct Student *next;
} Student;

Student *head = NULL;

void search(int number) {
    Student *current = head;
    int isFound = 0;

    while (current != NULL) {
        if (current->number == number) {
            printf("Ogrenci numarasi: %d\nOgrenci adi soyadi: %s %s\n", current->number, current->name, current->lastName);
            isFound = 1;
            break;
        }
        current = current->next;
    }

    if (!isFound) {
        printf("%d numarali kayit bulunamadi!\n", number);
    }
}

int isNumberExists(int number) {
    Student *current = head;

    while (current != NULL) {
        if (current->number == number) {
            return 1; // Numara listede bulundu
        }
        current = current->next;
    }

    return 0; // Numara listede bulunamadý
}

void add(int number, char name[MAX_NAME_LENGTH], char lastName[MAX_NAME_LENGTH], int *studentCount) {
    if (isNumberExists(number)) {
        printf("%d numarali kayit zaten var!\n", number);
        return;
    }

    Student *newStudent = (Student *)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Bellek ayirma basarisiz\n");
        exit(1);
    }

    newStudent->number = number;
    strcpy(newStudent->name, name);
    strcpy(newStudent->lastName, lastName);
    newStudent->next = NULL;

    if (head == NULL || head->number > newStudent->number) {
        newStudent->next = head;
        head = newStudent;
    } else {
        Student *current = head;
        while (current->next != NULL && current->next->number < newStudent->number) {
            current = current->next;
        }
        newStudent->next = current->next;
        current->next = newStudent;
    }
	
    (*studentCount)++;
}

void writeToStudentFile(const char* filename, int studentCount) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Dosya acilamadi\n");
        exit(1);
    }
    
    Student *current = head;
    while (current != NULL) {
        fprintf(file, "%d\n%s\n%s\n", current->number, current->name, current->lastName);
        current = current->next;
    }

    fclose(file);
}



void delete_(int number, int *studentCount) {
    Student *temp = head;
    Student *prev = NULL;

    while (temp != NULL && temp->number != number) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Ogrenci bulunamadi!\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    printf("Ogrenci silindi!\nNumara: %d\nAd Soyad: %s %s\n", temp->number, temp->name, temp->lastName);
    free(temp);
    (*studentCount)--;
}

void deleteFromFile(const char* filename, int number, int *studentCount) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Dosya acilamadi\n");
        exit(1);
    }

    FILE* tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        fclose(file);
        printf("Gecici dosya olusturulamadi\n");
        exit(1);
    }

    int num;
    char name[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];
    int found = 0;

    while (fscanf(file, "%d\n%s\n%s\n", &num, name, lastName) == 3) {
        if (num == number) {
            found = 1;
            continue;
        }

        fprintf(tempFile, "%d\n%s\n%s\n", num, name, lastName);
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    if (rename("temp.txt", filename) != 0) {
        printf("Dosya adi degistirilemedi\n");
        exit(1);
    }

    if (found) {
        (*studentCount)--;
        printf("Ogrenci silindi!\nNumara: %d\n", number);
    } else {
        printf("Ogrenci bulunamadi!\n");
    }
}

void printStudents(int studentCount) {
    printf("Okunan ogrenci bilgileri:\n");
    Student *current = head;

    while (current != NULL) {
        printf("-----------------------------\n");
        printf("Numara: %d\nAd: %s\nSoyad: %s\n", current->number, current->name, current->lastName);
        current = current->next;
    }
}

void addFromFile(const char* filename, int *studentCount) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Dosya acilamadi\n");
        exit(1);
    }

    int number;
    char name[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];

    while (fscanf(file, "%d\n%s\n%s\n", &number, name, lastName) == 3) {
        add(number, name, lastName, studentCount);
    }

    fclose(file);
}


int main() {
    int studentCount = 0;

    addFromFile(filename, &studentCount);

    int choose;
    int number;
    char name[MAX_NAME_LENGTH];
    char lastName[MAX_NAME_LENGTH];

    printf("1-ARAMA\n2-EKLEME\n3-SILME\n4-LISTELE\n5-CIKIS\nLutfen Secim Yapin: ");
    scanf("%d", &choose);

    while (choose != 5) {
        switch (choose) {
            case 1:
                printf("Aranacak ogrencinin numarasi: ");
                scanf("%d", &number);
                search(number);
                break;
            case 2:
                printf("Eklemek istediginiz ogrencinin numarasi, adi ve soyadi: ");
                scanf("%d %s %s", &number, name, lastName);
                add(number, name, lastName, &studentCount);
                writeToStudentFile(filename, studentCount);
                printf("%d - %s %s eklendi!\n", number, name, lastName);
                break;
            case 3:
                printf("Silmek istediginiz ogrencinin numarasi: ");
                scanf("%d", &number);
                delete_(number, &studentCount);
                deleteFromFile(filename,number,studentCount);
                break;
            case 4:
                printStudents(studentCount);
                break;
            default:
                printf("Yanlis secim! Lutfen dogru secim yapin...\n");
                break;
        }

        printf("1-ARAMA\n2-EKLEME\n3-SILME\n4-LISTELE\n5-CIKIS\nLutfen Secim Yapin: ");
        scanf("%d", &choose);
    }

    Student *current = head;
    while (current != NULL) {
        Student *temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
