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
    student.f_name = new char[128];
    student.l_name = new char[128];
    // Sequence of user input -> store in fields of `student`
    
    student.id = promptInt("id",0,999999999);
    std::cout << "Please enter the student's first name: ";
    std::cin.getline(student.f_name, 128);
    std::cout << "Please enter the student's last name: ";
    std::cin.getline(student.l_name, 128);
    student.n_assignments = promptInt("assignment",1,2147483647);
    std::cout << "\n";
    student.grades= new double[student.n_assignments];
    int i;
    for (i = 0; i < student.n_assignments; i++){
        student.grades[i] = promptDouble("grade",0.0,i);
        
    }
    // Call `CalculateStudentAverage(???, ???)`
    
    calculateStudentAverage(&student, &average);
    
    // Output `average`
    std::cout << "\n";
    std::cout << "Student: " << student.f_name << " " << student.l_name << " [" << student.id << "]\n";
    printf("  Average grade: %.1f\n", average);
    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an integer
    if(message.compare("id")==0){
        std::string id;
        bool flag1 = true;
        bool flag2 = true;
        while (flag1==true || flag2==true){
            std::cout << "Please enter the student's id number: ";
            std::cin >> id;
            std::cin.ignore();
            for (int i = 0; i < id.size(); i++){
                int temp = (int)id[i];
                if (temp>=48 && temp<=57){
                    flag1 = false;
                } else {
                    flag1 = true;
                    std::cout << "Sorry, I cannot understand your answer\n";
                    break;
                }
            }
            if (flag1 == false){
                if (std::stoi(id) >= min && std::stoi(id) <= max){
                    flag2 = false;
                } else {
                    std::cout << "Sorry, I cannot understand your answer\n";
                }
            }
        }
        return std::stoi(id);
    } else if (message.compare("assignment")==0) {
        std::string assignment;
        bool flag1 = true;
        bool flag2 = true;
        while (flag1==true || flag2==true){
            std::cout << "Please enter how many assignments were graded: ";
            std::cin >> assignment;
            std::cin.ignore();
            for (int i = 0; i < assignment.size(); i++){
                int temp = (int)assignment[i];
                if (temp>=48 && temp<=57){
                    flag1 = false;
                } else {
                    flag1 = true;
                    std::cout << "Sorry, I cannot understand your answer\n";
                    break;
                }
            }
            if (flag1 == false){
                if (std::stoi(assignment) >= min && std::stoi(assignment) <= max){
                    flag2 = false;
                } else {
                    std::cout << "Sorry, I cannot understand your answer\n";
                }
            }
        }
        return std::stoi(assignment);
    }else{
        return 0;
    }
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    std::string grade;
    bool flag1 = true;
    bool flag2 = true;
    while (flag1==true || flag2==true){
        std::cout << "Please enter grade for assignment " << max << ": ";
        std::cin >> grade;
        std::cin.ignore();
        for (int i = 0; i < grade.size(); i++){
            int temp = (int)grade[i];
            if ((temp>=48 && temp<=57) || temp == 46){
                flag1 = false;
            } else {
                flag1 = true;
                std::cout << "Sorry, I cannot understand your answer\n";
                break;
            }
        }
        if (flag1 == false){
            if (std::stod(grade) >= min){
                flag2 = false;
            } else {
                std::cout << "Sorry, I cannot understand your answer\n";
            }
        }
    }
    return std::stod(grade);
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    // Code to calculate and store average grade
    Student *ptr = (Student*)object;
    int howmany = (*ptr).n_assignments;
    double *grades = (*ptr).grades;
    double sumGrades = 0;
    int count = 0;
    for (int i=0; i < howmany; i++){
        sumGrades += grades[i];
        count++;
    }
    *avg = (sumGrades/count);
}
