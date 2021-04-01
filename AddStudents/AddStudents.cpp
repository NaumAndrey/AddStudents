/*Практическая работа 2.5 №1*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <limits>
#include <string>


using namespace std;

struct students {
    char fio[100];
    char sex[100];
    int groupNumber;
    int groupListNumber;
    int gradesForTheLastSession[8];
    char formOfEducation[100];
    time_t dataChanges;
};

int Size;

// Создание новой записи о студенте
void createStudents () {

    students stu;
    string path = "test_2.txt";
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open()) {
        cout << "Eror!";
    } else {

        cout << "\nEnter the FIO: ";
        cin >> stu.fio;

        cout << "\nEnter the sex: ";
        cin >> stu.sex;

        cout << "\nEnter the Number group: ";
        cin >> stu.groupNumber;

        cout << "\nEnter the Group List Number: ";
        cin >> stu.groupListNumber;

        cout << "\nEnter the Grades For The Last Session: ";

        for (int i = 0; i < 8; i++) {
            cin >> stu.gradesForTheLastSession[i];
        }

        cout << "\nEnter the Form Of Education: ";
        cin >> stu.formOfEducation;

        stu.dataChanges = time (NULL);
        cout << "\n";

        cout << "FIO: " << stu.fio << "\n";
        cout << "SEX: " << stu.sex << "\n";
        cout << "Group Number: " << stu.groupNumber << "\n";
        cout << "Group List Number: " << stu.groupListNumber << "\n";
        cout << "Grades For The Last Session: " << stu.gradesForTheLastSession << "\n";
        cout << "The Form Of Education: " << stu.formOfEducation << "\n";
        cout << "The Data Changes: " << stu.dataChanges << "\n";

        fs << stu.fio << '\n';
        fs << stu.sex << '\n';
        fs << stu.groupNumber << '\n';
        fs << stu.groupListNumber << '\n';

        for (int i = 0; i < 8; i++) {
            fs << stu.gradesForTheLastSession[i] << " ";
        }
        fs << "\n";

        fs << stu.formOfEducation << '\n';
        fs << stu.dataChanges << '\n';
    }

        fs.close();
}

void makingChangesToAnexiStingRecord() {

    students stu;
    string path = "test_2.txt";
    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);

    if (!fs.is_open()) {
        cout << "Eror!";
    } else {
        cout << "\nEdit FIO: ";
        cin >> stu.fio;

        cout << "\nEdit the sex: ";
        cin >> stu.sex;

        cout << "\nEdit the Number group: ";
        cin >> stu.groupNumber;

        cout << "\nEdit the Group List Number: ";
        cin >> stu.groupListNumber;

        cout << "\nEdit the Grades For The Last Session: ";
        for (int i = 0; i < 8; i++) {
            cin >> stu.gradesForTheLastSession[i];
        }

        cout << "\nEdit the Form Of Education: ";
        cin >> stu.formOfEducation;

        cout << "FIO: " << stu.fio << "\n";
        cout << "SEX: " << stu.sex << "\n";
        cout << "Group Number: " << stu.groupNumber << "\n";
        cout << "Group List Number: " << stu.groupListNumber << "\n";
        cout << "Grades For The Last Session: " << stu.gradesForTheLastSession << "\n";
        cout << "The Form Of Education: " << stu.formOfEducation << "\n";
        cout << "The Data Changes: " << stu.dataChanges << "\n";

        fs << stu.fio << '\n';
        fs << stu.sex << '\n';
        fs << stu.groupNumber << '\n';
        fs << stu.groupListNumber << '\n';
        fs << stu.gradesForTheLastSession << '\n';
        fs << stu.formOfEducation << '\n';
        fs << stu.dataChanges << '\n';
    }

        fs.close();
}

// функция возврат заначения
students * getAllDataFromFile() {

    students* List = NULL; // 
    ifstream file;

    file.open("test_2.txt");
    while (!file.is_open()) {

        cout << "file error! \n";
        return NULL;
    }

    Size = 0;

    while (!file.eof()) {
        List = (students*) realloc(List, (Size + 1) * sizeof(students));
        students* newStudent = List + Size;
        file.getline(newStudent->fio, 100);
        file.getline(newStudent->sex, 100);
        file >> newStudent->groupNumber;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        file >> newStudent->groupListNumber;

        file.ignore(numeric_limits<streamsize>::max(), '\n');
        for (int i = 0; i < 8; i++) {
            file >> newStudent->gradesForTheLastSession[i];
        }

        file.ignore(numeric_limits<streamsize>::max(), '\n');
        file.getline(newStudent->formOfEducation, 100);
        file >> newStudent->dataChanges;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        Size++;
    }

    file.close();
    return List; // возращает указатель впамати
}

// маска для вывода полей
void printStudents(students* stu) {
    
    for (int i = 0; i < Size; i++) { 
        students* Current = stu + i;
        cout << "FIO: " << Current->fio << "\n";
        cout << "SEX: " << Current->sex << "\n";
        cout << "Group Number: " << Current->groupNumber << "\n";
        cout << "Group List Number: " << Current->groupListNumber << "\n";
        cout << "Grades For The Last Session: " << " ";
        for (int i = 0; i < 8; i++) {
            cout << Current->gradesForTheLastSession[i] << " ";
        }
        cout << "\n";

        cout << "The Form Of Education: " << Current->formOfEducation << "\n";
        cout << "The Data Changes: " << ctime(&(Current->dataChanges)) << "\n";
    }
    stu = stu + 1;
}

// функция изменения записи
void editPrintStudents(students* stu) {
    
    ofstream file;
    string path = "test_2.txt";

    file.open(path, std::ios_base::trunc);

    if (!file.is_open()) {
        cout << "file error! \n";
    } else {

        for (int i = 0; i < Size; i++) { 

            students* Current = stu + i;

            file << Current->fio << '\n';
            file << Current->sex << '\n';
            file << Current->groupNumber << '\n';
            file << Current->groupListNumber << '\n';

            for (int i = 0; i < 8; i++) {
                file << Current->gradesForTheLastSession[i] << " ";
            }  
            file << "\n";

            file << Current->formOfEducation << '\n';
            file << Current->dataChanges;
            //file << ctime(&(Current->dataChanges));

            if (!(i == Size - 1) ) {
                file << '\n';
            }
        }
            file.close();
    }

}

// функция записывает в память
void memoryEdit(students* stu) {

    students* Current;

    for (int i = 0; i < Size; i++) {
        Current = stu + i;
        cout << i + 1 << ". " << Current->fio << '\n';
    }

    cout << "Enter the students: ";

    int number;
    cin >> number;
    Current = stu + number - 1;

    cout << "FIO: ";
    cin >> Current->fio;
    cout << "SEX: ";
    cin >> Current->sex;
    cout << "Group Number: ";
    cin >> Current->groupNumber;
    cout << "Group List Number: ";
    cin >> Current->groupListNumber;
    cout << "Grades For The Last Session: ";

    for (int i = 0; i < 8; i++) {
        cin >> Current->gradesForTheLastSession[i];
    }
    
    cout << "The Form Of Education: ";
    cin >> Current->formOfEducation;
    cout << "The Data Changes: ";

    cin.getline(Current->sex, 100);

    editPrintStudents(stu);
}

//Вывод информации обо всех студентах группы N. N – инициализируется пользователем

void outputAllStudentsGroupN(students* List) {

    int n;
    cout << "Enter the group number:" << endl;
    cin >> n;

    for (int i = 0; i < Size; i++) {

        if (List[i].groupNumber == n) {

            cout << List[i].fio << endl;
            cout << List[i].sex << endl;
            cout << List[i].groupNumber << endl;
            cout << List[i].groupListNumber << endl;

            cout << "Term grades:";
            for (int j = 0; j < 8; j++) {
                cout << List[i].gradesForTheLastSession[j] << " ";

            }
            cout << endl;

            cout << List[i].formOfEducation << endl;
            cout << ctime(&(List[i].dataChanges)) << endl;
        }
    }
}

void listTop(students* List)
{
    cout << "Top students:" << endl << endl;
    // структура для хранения средних балов
    struct sortList
    {
        unsigned int number;
        double score;
    };

    sortList* SortList = (sortList*) malloc(sizeof(sortList) * Size);

    for (int i = 0; i < Size; i++) {

        int sum = 0;
        (SortList + i)->number = i;

        for (int j = 0; j < 8; j++) {
            sum = (sum + List[i].gradesForTheLastSession[j]);
            (SortList + i)->score = (double)sum / 8;
        }
    }

    int sorted = 0;
    int currentMaxUnsorted = Size - 1;
    while (!sorted)
    {
        sorted = 1;
        for (int i = 0; i < currentMaxUnsorted; i++)
        {
            if ((SortList + i)->score - (SortList + i + 1)->score > 0)
            {
                sortList Buffer;
                Buffer.number = (SortList + i)->number;
                Buffer.score = (SortList + i)->score;
                (SortList + i)->number = (SortList + i + 1)->number;
                (SortList + i)->score = (SortList + i + 1)->score;
                (SortList + i + 1)->number = Buffer.number;
                (SortList + i + 1)->score = Buffer.score;
                sorted = 0;
            }
        }
        currentMaxUnsorted--; // последний уже отсортирован и проверсять не надо 
    }

    for (unsigned int i = Size - 1, j = 0; i >= 0 && j < 3; i--, j++)
    {
        cout << List[(SortList + i)->number].fio << endl;
        cout << List[(SortList + i)->number].sex << endl;
        cout << List[(SortList + i)->number].groupNumber << endl;
        cout << List[(SortList + i)->number].groupListNumber << endl;
        cout << "Term grades:";
        for (int j = 0; j < 8; j++) {
            cout << List[(SortList + i)->number].gradesForTheLastSession[j] << " ";
        }
        cout << endl;
        cout << List[(SortList + i)->number].formOfEducation << endl;
        cout << ctime(&(List[(SortList + i)->number].dataChanges)) << endl;
    }
    std::cout << std::endl << std::endl;
    free(SortList); // осовобождения памяти функции малок
}

int main()
{
    students* stu_1 = getAllDataFromFile();
    printStudents(stu_1);

    //createStudents();

    //makingChangesToAnexiStingRecord();
   
    //outputAllStudentsGroupN();


    //memoryEdit(stu_1);


    outputAllStudentsGroupN(stu_1);

    //listTop(stu_1);

    cin.get();
}




