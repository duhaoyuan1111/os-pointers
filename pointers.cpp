// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average;
    double howmany;
    student.f_name = new char[128];
    student.l_name = new char[128];
    // Sequence of user input -> store in fields of `student`

    std::cout << "Please enter the student's id number: ";
    std::cin >> student.id;
    std::cin.ignore();
    std::cout << "Please enter the student's first name: ";
    std::cin.getline(student.f_name, 128);
    std::cout << "Please enter the student's last name: ";
    std::cin.getline(student.l_name, 128);
    std::cout << "Please enter how many assignments were graded: ";
    std::cin >> student.n_assignments;
    howmany = student.n_assignments;

    student.grades= new double[student.n_assignments];
    int i;
    for (i = 0; i < student.n_assignments; i++){
        std::cout << "Please enter grade for assignment " << i << ":";
        std::cin >> student.grades[i];
    }
    // Call `CalculateStudentAverage(???, ???)`
    double *avgpointer = &howmany;

    calculateStudentAverage(student.grades, avgpointer);
    // Output `average`
    std::cout << "Student: " << student.f_name << " " << student.l_name << " [" << student.id << "]";
    std::cout << "  Average grade: " << average;
    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    int i;
    int sum = 0;
    for (i = 0; i < *avg; i++){
        sum += object;
    }
    *avg = sum;
}
