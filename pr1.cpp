#include <iostream>
#include <string>
using namespace std;


struct Student 
{
    std::string fullname;
    char sex{};
    int groupNumber{};
    int listNumber{};
    float grades[8]{}; //3 экза и 5 дифф
};


// 1. создание новой записи  о студенте
void createNewStudent(Student* students, int& size)
{
    if (size < 10)
    {
        std::cout << "Enter student's full name: "; // имя
        std::cin.ignore(); // очистка буфера ввода
        getline(std::cin, students[size].fullname); // считывает строку с пробелами 

        std::cout << "Enter student's gender (M/W): "; // пол
        std::cin >> students[size].sex;

        std::cout << "Enter student's group number: "; // номер группы
        std::cin >> students[size].groupNumber;

        std::cout << "Enter student's list number: "; // номер в списке
        std::cin >> students[size].listNumber;

        std::cout << "Enter student's grades for 3 exams: "; // экз
        for (int i = 0; i < 3; i++) 
        {
           
            std::cin >> students[size].grades[i];
        }

        std::cout << "Enter student's grades for 5 differentiated tests: "; // дифф
        for (int i = 3; i < 8; i++) 
        {
            std::cin >> students[size].grades[i];
        }

        size++;
    }
    else 
    {
        std::cout << "Array is full" << std::endl; // массив заполнен
    }
}
// 2. внесение изменений
void editStudent(Student* students, int studentCount) {
    std::string name;
    std::cout << "Enter student's name to edit: ";
    std::cin >> name;

    for (int i = 0; i < studentCount; i++) {
        if (students[i].fullname == name) {
            std::cout << "Enter student's new name: ";
            std::cin >> students[i].fullname;
            std::cout << "Enter student's new sex: ";
            std::cin >> students[i].sex;
            std::cout << "Enter student's new group number: ";
            std::cin >> students[i].groupNumber;
            std::cout << "Enter student's new list number: ";
            std::cin >> students[i].listNumber;
            std::cout << "Enter student's new grades for 3 exams and 5 tests: ";
            for (int j = 0; j < 8; j++) {
                std::cin >> students[i].grades[j];
            }
            break;
        }
    }
}


// 3. вывод всех данных о студентах
void displayStudents(Student* students, int size) 
{
    for (int i = 0; i < size; i++) 
    {
        std::cout << "Student " << i + 1 << ": " << std::endl;
        std::cout << "Full Name: " << students[i].fullname << std::endl;
        std::cout << "Sex: " << students[i].sex << std::endl;
        std::cout << "Group Number: " << students[i].groupNumber << std::endl;
        std::cout << "List Number: " << students[i].listNumber << std::endl;
        std::cout << "Grades: ";
        for (int j = 0; j < 8; j++) 
        {
            std::cout << students[i].grades[j] << " ";
        }
        std::cout << std::endl;
    }
}

// 4. вывод информации о студентах группы 
void displayStudentsOfGroup(Student* students, int size, int groupNumber)
{
    for (int i = 0; i < size; i++) 
    {
        if (students[i].groupNumber == groupNumber) 
        {
            std::cout << "Student " << i + 1 << ": " << std::endl;
            std::cout << "Full Name: " << students[i].fullname << std::endl;
            std::cout << "Sex: " << students[i].sex << std::endl;
            std::cout << "Group Number: " << students[i].groupNumber << std::endl;
            std::cout << "List Number: " << students[i].listNumber << std::endl;
            std::cout << "Grades: ";
            for (int j = 0; j < 8; j++) 
            {
                std::cout << students[i].grades[j] << " ";
            }
            std::cout << std::endl;
        }
    }
}

// 5. топ успешных студентов 
void displayTopStudents(Student* students, int size) 
{
    float max = 0;
    int index = -1;
    for (int i = 0; i < size; i++) 
    {
        float sum = 0;
        for (int j = 0; j < 8; j++) 
        {
            sum += students[i].grades[j];
        }
        if (sum > max) 
        {
            max = sum;
            index = i;
        }
    }
    if (index >= 0) 
    {
        std::cout << "Top Student: " << std::endl;
        std::cout << "Full Name: " << students[index].fullname << std::endl;
        std::cout << "Sex: " << students[index].sex << std::endl;
        std::cout << "Group Number: " << students[index].groupNumber << std::endl;
        std::cout << "List Number: " << students[index].listNumber << std::endl;
        std::cout << "Grades: ";
        for (int j = 0; j < 8; j++) 
        {
            std::cout << students[index].grades[j] << " ";
        }
        std::cout << std::endl;
    }
}

// 6. кол-во м и ж 
void displayGenderCount(Student* students, int size) 
{
    int menCount = 0;
    int womenCount = 0;
    for (int i = 0; i < size; i++) 
    {
        if (students[i].sex == 'M')
        {
            menCount++;
        }
        else if (students[i].sex == 'W')
        {
            womenCount++;
        }
    }
    std::cout << "Men Students: " << menCount << std::endl;
    std::cout << "Women Students: " << womenCount << std::endl;
}

// 7. стипа
void displayStipendiumStudents(Student* students, int size) 
{
    for (int i = 0; i < size; i++)
    {
        bool stipendium = true;
        bool good = true;
        bool excellent = true;
        for (int j = 0; j < 8; j++) 
        {
            if (students[i].grades[j] < 8)
            {
                stipendium = false;
            }
            if (students[i].grades[j] < 7)
            {
                good = false;
            }
            if (students[i].grades[j] < 8.5) 
            {
                excellent = false;
            }
        }

        if (!stipendium)
        {
            std::cout << students[i].fullname << " does not receive a stipendium." << std::endl;
        }
        if (good && !excellent) 
        {
            std::cout << students[i].fullname << " gets only \"good\" grades." << std::endl;
        }
        if (excellent) 
        {
            std::cout << students[i].fullname << " gets only \"excellent\" grades." << std::endl;
        }
    }
}

// 8. вывод по номеру в списке
void displayStudentByListNumber(Student* students, int size, int listNumber)
{
    for (int i = 0; i < size; i++) 
    {
        if (students[i].listNumber == listNumber)
        {
            std::cout << "Student " << i + 1 << ": " << std::endl;
            std::cout << "Full Name: " << students[i].fullname << std::endl;
            std::cout << "Sex: " << students[i].sex << std::endl;
            std::cout << "Group Number: " << students[i].groupNumber << std::endl;
            std::cout << "List Number: " << students[i].listNumber << std::endl;
            std::cout << "Grades: ";
            for (int j = 0; j < 8; j++) 
            {
                std::cout << students[i].grades[j] << " ";
            }
            std::cout << std::endl;
        }
    }
}

int main()
{
   
    Student* students = new Student[10];
    int size = 0;
    int option;
    do
    {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Create new student record" << std::endl;
        std::cout << "2. Making changes" << std::endl;
        std::cout << "3. Display all students" << std::endl;
        std::cout << "4. Display students of a specific group" << std::endl;
        std::cout << "5. Display top student" << std::endl;
        std::cout << "6. Display men and women students count" << std::endl;
        std::cout << "7. Display students who do not receive stipendium or get only \"good\" or \"excellent\" grades" << std::endl;
        std::cout << "8. Display student by list number" << std::endl;
        std::cout << "9. IDZ" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> option;

        switch (option)
        {
        case 1:
            createNewStudent(students, size);
            break;
        case 2:
            editStudent(students, size);
            break;
        case 3:
            displayStudents(students, size);
            break;
        case 4:
            int groupNumber;
            std::cout << "Enter group number: ";
            std::cin >> groupNumber;
            displayStudentsOfGroup(students, size, groupNumber);
            break;
        case 5:
            displayTopStudents(students, size);
            break;
        case 6:
            displayGenderCount(students, size);
            break;
        case 7:
            displayStipendiumStudents(students, size);
            break;
        case 8:
            int listNumber;
            std::cout << "Enter list number: ";
            std::cin >> listNumber;
            displayStudentByListNumber(students, size, listNumber);
            break;
        case 9:
          {
            struct Lecturer
            {
                std::string fio;
                char sex;
                int age;
                std::string discipline;
                std::string email;
                int group_number;
            };

           
                // Создаем массив структур для хранения информации о преподавателях
                   Lecturer lecturers[3];
                   int numLecturer = 0;
                   int choice;


                // Заполняем массив данными
                for (int i = 0; i < 3; i++) 
                {
                    cout << "Enter the full name of the lecturer: "; // фио преподавателя
                    std::cin.ignore();
                    getline(std::cin, lecturers[i].fio);

                    std::cout << "Enter the sex of the lecturer: "; // пол
                    std::cin >> students[size].sex;

                    cout << "Enter the lecturer's age: "; // возраст 
                    cin >> lecturers[i].age;

                    cout << "Enter the name of the discipline taught by the lecturer: "; // название дисциплины
                    std::cin.ignore();
                    getline(std::cin, lecturers[i].discipline);

                    cout << "Enter the email of the lecturer: "; // почта преподавателя
                    std::cin.ignore();
                    getline(std::cin, lecturers[i].email);

                    cout << "Enter the number of the group where the lecturer teaches classes: "; // номер группы, у которой преподаёт
                    cin >> lecturers[i].group_number;
                }

                // Выводим меню для выбора способа поиска информации о преподавателе
              
                do 
                {
                    cout << "\nChoose a way to search for information about the lecturer:\n"; // способ поиска информации 
                    cout << "1. By name\n"; // по фамилии
                    cout << "2. By group number\n";
                    cout << "3. By the name of the disciplines\n";
                    cout << "4. Exit\n";
                    cout << "Enter the number of the menu: ";
                    cin >> choice;

                    // Обрабатываем выбор пользователя
                    switch (choice) 
                    { 
                        
                    case 1: 
                    {
                        // Поиск преподавателя по фамилии
                        std::string fio;
                        cout << "Enter the full name of the lecturer: ";
                        cin >> fio;

                        for (int i = 0; i < 3; i++)
                        {
                            if (lecturers[i].fio.find(fio) != string::npos)
                            {
                                cout << "Fio: " << lecturers[i].fio << endl;
                                cout << "Sex: " << lecturers[i].sex << endl;
                                cout << "Age: " << lecturers[i].age << endl;
                                cout << "Discipline: " << lecturers[i].discipline << endl;
                                cout << "Email: " << lecturers[i].email << endl;
                                cout << "Group number: " << lecturers[i].group_number << endl;
                                cout << endl;
                            }
                        }
                        break;
                    }
                    case 2: 
                    {


                        // Поиск преподавателя по номеру группы
                        int group_number;
                        cout << "Enter the number of the group: ";
                        cin >> group_number;

                        for (int i = 0; i < 3; i++)
                        {
                            if (lecturers[i].group_number == group_number)
                            {
                                cout << "Fio: " << lecturers[i].fio << endl;
                                cout << "Sex: " << lecturers[i].sex << endl;
                                cout << "Age: " << lecturers[i].age << endl;
                                cout << "Discipline: " << lecturers[i].discipline << endl;
                                cout << "Email: " << lecturers[i].email << endl;
                                cout << "Group number: " << lecturers[i].group_number << endl;
                                cout << endl;
                            }
                        }
                    }
                        break;
                    case 3:
                    {
                        // Поиск преподавателя по наименованию дисциплины
                        string discipline;
                        cout << "Enter the name of the discipline: ";
                        getline(cin, discipline);

                        for (int i = 0; i < 3; i++)
                        {
                            if (lecturers[i].discipline == discipline)
                            {
                                cout << "Fio: " << lecturers[i].fio << endl;
                                cout << "Sex: " << lecturers[i].sex << endl;
                                cout << "Age: " << lecturers[i].age << endl;
                                cout << "Discipline: " << lecturers[i].discipline << endl;
                                cout << "Email: " << lecturers[i].email << endl;
                                cout << "Group number: " << lecturers[i].group_number << endl;
                                cout << endl;
                            }
                        }
                        break;
                    }
                        case 4: 
                        {
                            // Выход из программы
                            cout << "Goodbye!" << endl;
                            break;
                        }
                        default:
                        // Неверный выбор
                        cout << "Wrong choice. Please enter the number of the menu from 1 to 4." << endl;
                        break;
                    }

                } while (choice != 4);

          }
        }
    } while (option != 0);

    delete[] students; // освобождаем память 

    return 0;
}
