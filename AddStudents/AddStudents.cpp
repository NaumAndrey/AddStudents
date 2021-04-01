/*Практическая работа 2.5 №1*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <limits>


using namespace std;

struct students {
    char fio[100];
    char sex[100];
    double groupNumber;
    int groupListNumber;
    double gradesForTheLastSession;
    char formOfEducation[100];
    time_t dataChanges;
};

int Size;

void createStudents () {

    students stu;
    string path = "test_3.txt";
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
        cin >> stu.gradesForTheLastSession;

        cout << "\nEnter the Form Of Education: ";
        cin >> stu.formOfEducation;

        stu.dataChanges = time (NULL);

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

void makingChangesToAnexiStingRecord() {

    students stu;
    string path = "test_3.txt";
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
        cin >> stu.gradesForTheLastSession;

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
students* getAllDataFromFile() {
    students* List = NULL;
    ifstream file;
    file.open("test_2.txt");
    while (!file.is_open()) {

        cout << "file error! \n";
        return NULL;
    }

    Size = 0;

    while (Size != 3) {
        List = (students*) realloc(List, (Size + 1) * sizeof(students));
        students* newStudent = List + Size;
        file.getline(newStudent->fio, 100);
        file.getline(newStudent->sex, 100);
        file >> newStudent->groupNumber;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        file >> newStudent->groupListNumber;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        file >> newStudent->gradesForTheLastSession;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        file.getline(newStudent->formOfEducation, 100);
        file >> newStudent->dataChanges;
        file.ignore(numeric_limits<streamsize>::max(), '\n');
        Size++;
    }

    file.close();
    return List;
}

void printStudents(students* stu) {
    
    for (int i = 0; i < Size; i++) { 
        students* Current = stu + i;
        cout << "FIO: " << Current->fio << "\n";
        cout << "SEX: " << Current->sex << "\n";
        cout << "Group Number: " << Current->groupNumber << "\n";
        cout << "Group List Number: " << Current->groupListNumber << "\n";
        cout << "Grades For The Last Session: " << Current->gradesForTheLastSession << "\n";
        cout << "The Form Of Education: " << Current->formOfEducation << "\n";
        cout << "The Data Changes: " << ctime(&(Current->dataChanges)) << "\n";
    }
    stu = stu + 1;
}


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
            file << Current->gradesForTheLastSession << '\n';
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

    //cout << "FIO: ";
    //cin >> Current->fio;
    //cout << "SEX: ";
    //cin >> Current->sex;
    //cout << "Group Number: ";
    //cin >> Current->groupNumber;
    //cout << "Group List Number: ";
    //cin >> Current->groupListNumber;
    cout << "Grades For The Last Session: ";
    cin >> Current->gradesForTheLastSession;
    //cout << "The Form Of Education: ";
    //cin >> Current->formOfEducation;
    //cout << "The Data Changes: ";

    //cin.getline(Current->sex, 100);

    editPrintStudents(stu);
}

//void outputallstudentsgroupn () {
//
//    students stu;
//    ifstream file;
//    file.open("test_3.txt");
//
//    char buff[1024];
//    int i = 0;
//
//    while (!file.eof()) {
//
//        if (stu.gradesforthelastsession < 4) {
//
//            file.getline(buff, sizeof(buff));
//            cout << buff << "\n";
//
//            cout << "fio: " << stu.fio;
//            cout << "\ngrades for the last session: " << stu.gradesforthelastsession;
//        }
//
//        else {
//            cout << stu.fio;
//            cout << "\n error";
//            cout << stu.gradesforthelastsession;
//        }
//    }
//
//    file.close();
//    cin.ignore();
//}

void listStu(students * stu) {

    students* Current;

    for (int i = 0; i < Size; i++) {
        Current = stu + i;
        cout << i + 1 << ". " << Current->groupNumber<< '\n';
    }

    cout << "Enter the group: ";
    int number;
    cin >> number;
    Current = stu + number - 1;
    cout << endl;

    //cin >> Current->groupNumber;

    if (number) {
        printStudents(stu);
    }

    else {
        cout << "Error!";
    }

    

    //cin >> Current->gradesForTheLastSession;
}

//Вывод информации обо всех студентах группы N. N – инициализируется пользователем

//void outputAllStudentsGroupN(students*stu) {
//     
//}


int main()
{
    //createStudents();

    //makingChangesToAnexiStingRecord();
   
    //outputAllStudentsGroupN();

    students* stu_1 = getAllDataFromFile();
    printStudents(stu_1);

    //memoryEdit(stu_1);

    listStu(stu_1);

    cin.get();
}




