# Student Registration System
This project is an example of a student registration system. It is written in C language and is used to manage student information such as storing, adding, deleting, searching, and listing.

## How to Use?
### Compilation and Execution

As it's written in C, you'll need a C compiler (like gcc). To compile your project files, use the following command in your terminal or command prompt:
`gcc main.c -o StudentSystem`

This command will compile the main.c file into an executable named StudentSystem. After that, you can run the executable file as follows:
`./StudentSystem`

## Menu Options

When the program runs, it presents the user with five different options:

## SEARCH: 
Search by student number.
## ADD:
Enter information to add a new student.
## DELETE: 
Remove a student by their number.
## LIST:
Display all student information.
## EXIT: 
Exit the program.

## File Operations

Student information is stored in the Students.txt file.
Upon starting the program, previously saved student information is read from this file and stored in memory.
Every addition, deletion, or listing operation updates the file by writing to it.

## Important Notes

Student numbers must be unique. You cannot add multiple students with the same number.
Upon program startup, the previous student information is read from the Students.txt file and stored in memory.
When the program ends, the updated student information is rewritten to the Students.txt file.

# ÖğrenciKayıtSistemi
Bu proje, öğrenci bilgilerini depolamak, eklemek, silmek, aramak ve listelemek gibi işlemleri gerçekleştiren bir #öğrenci kayıt sistemine örnek olarak yazılmıştır. #C dilinde yazılmıştır.

## NasılKullanılır?
### DerlemeVeÇalıştırma

# C dilinde yazıldığı için bir C derleyicisine ihtiyacınız olacak (örneğin gcc). Projeyi derlemek için terminal veya komut istemcisinde aşağıdaki komutu kullanabilirsiniz:
`gcc main.c -o StudentSystem`

Bu komut, main.c dosyasını StudentSystem adında bir yürütülebilir dosyaya derleyecektir. Ardından, şu şekilde yürütülebilir dosyayı çalıştırabilirsiniz:
`./StudentSystem`

## MenüSeçenekleri

Program çalıştığında, kullanıcıya beş farklı seçenek sunar:

## ARAMA: 
Öğrenci numarasına göre arama yapar.
## EKLE:
Yeni bir öğrenci eklemek için bilgi girişi yapar.
## SİL: 
Öğrenciyi numarasına göre siler.
## LİSTE:
Tüm öğrenci bilgilerini görüntüler.
## ÇIKIŞ: 
Programdan çıkar.

## Dosyaİşlemleri

Öğrenci bilgileri Students.txt dosyasında saklanır.
Program başladığında, önceki kaydedilmiş öğrenci bilgileri bu dosyadan okunur ve bellekte saklanır.
Her ekleme, silme veya listeleme işlemi, bilgileri güncellemek için dosyaya yazma işlemi gerçekleştirir.

## ÖnemliNotlar

Öğrenci numaraları benzersiz olmalıdır. Aynı numaraya sahip birden fazla öğrenci ekleyemezsiniz.
Program başlatıldığında, önceki öğrenci bilgileri Students.txt dosyasından okunur ve bellekte saklanır.
Program sonlandığında, güncellenmiş öğrenci bilgileri Students.txt dosyasına tekrar yazılır.

