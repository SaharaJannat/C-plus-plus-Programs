#include<bits/stdc++.h>
using namespace std;

float array[10];

class Person
{
public:
    string Name;
    int Id;

    Person(string name, int id);
};

Person::Person(string name, int id)
{
    Name=name;
    Id=id;
}

class Student:public Person
{
private:
    float GPA;
    int ACM_Solve;

public:
	Student(string n, int a, float g, int s) : Person(n,a), GPA(g), ACM_Solve(s) {}
	void showStudent();

	int checkGPA(float gpa)
    {
        if(ACM_Solve>=100 && GPA>=3.2 )
            return 1;

        else return 0;
    }

    float accessGPA()
    {
        return GPA;
    }
};

void Student::showStudent()
{
    cout << setw(10) << Name << setw(13) << Id << setw(10) <<  GPA << setw(13) << ACM_Solve << endl << endl;
}

int main()
{
    int i,j;
    Student *performance[10]=
    {
        new Student("Maria",1001,3.40,45),
        new Student("Shara",1002,3.91,110),
        new Student("Jannat",1003,3.45,150),
        new Student("Fariha",1004,3.26,310),
        new Student("Rahim",1005,3.28,250),
        new Student("Abir",1006,3.88,100),
        new Student("Jems",1007,3.63,200),
        new Student("Atif",1008,3.27,99)
    };

    float temp;
    int counter=0;
    float maximum;

    for(i=7;i>=0;i--)
    {
        array[i]=performance[i]->accessGPA();
        for(j=0;j<7-i;j++)
        {
            if(array[j]>array[j+1])
            {
                temp=array[j+1];
                array[j+1]=array[j];
                array[j] = temp ;
            }
        }
    }

    cout << "TOP 5 students on the Honor Board are:" << endl << endl;
    cout << setw(10) << "Student Name"  <<  setw(10) << "ID"  << setw(10) << "GPA" << setw(25) << "ACM Problems Solve" << endl  ;
    cout << setw(10) << "____________"  <<  setw(10) << "__"  << setw(10) << "___" << setw(25) << "__________________" << endl << endl ;

    for(i=7;i>=0;i--)
    {
        maximum=array[i];

        for(j=0;j<7;j++)
        {
            if(performance[j]->checkGPA(maximum)==1)
            {
                counter++;
                performance[j]->showStudent();
            }

            if(counter==5) break;
        }
    }
    return 0;
}
