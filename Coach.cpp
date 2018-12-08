#include<bits/stdc++.h>

using namespace std;

class Date
{
public:
    int day,month,year;
    Date() {};
    Date(int d,int m,int y)
    {
        day=d;
        month=m;
        year=y;
    }

};

class Person                 ///Person class
{
public:
    string name;
    Date d1;
    Person() {}; ///Constructor-1 /Default Constructor
    Person(string n)
    {
        name=n;
    }
    Person(string n,Date *d)
    {
        name=n;
        d1=*d;
    }
};

    class Department
    {
    public:
        string dept_name;
        Department() {};
        Department(string n)
        {
            dept_name=n;
        }
    };

    class Student : public Person             /// Student class
    {
    public:
        int id,ACM,prob_solve;
        Department d;
        Student() {};                                ///Constructor-1 /Default Constructor
        Student(string n,Date *d2,Department *dp,int dd,int acm,int solve) : Person(n,d2)  ///constructor-2
        {
            id=dd;
            d=*dp;
            ACM=acm;
            prob_solve=solve;
        }
        View_Student_Info()                        ///function for viewing student info
        {
            cout<<"Student name: "<<name<<endl;
            cout<<"Department: "<<d.dept_name<<endl;
            cout<<"Students Birthday: "<<d1.day<<"-"<<d1.month<<"-"<<d1.year<<endl;
            cout<<"NUMBER OF ACM PARTICIPATION: "<<ACM<<endl;
            cout<<"NUMBER OF SOLVED PROBLEMS: "<<prob_solve<<endl;
        }
    };

    class Faculty : public Person                               ///faculty class
    {
    public:
        Student *s;
        string designation;
        Department dp;
        Faculty() {};                                                 ///Constructor-1 /Default Constructor
        Faculty(string d,string n,Department *dp1):Person(d)          ///constructor-2
        {
            designation=n;
            dp=*dp1;
        }
        View_Faculty()                                                ///faculty viewing function
        {
            cout<<"Name: "<<name<<endl;
            cout<<"Department: "<<dp.dept_name<<endl;
            cout<<"Designation: "<<designation<<endl;
        }
        int select_coach(Student *s1)
        {
            s=s1;
            if(s->ACM>=3&&s->prob_solve>300)
                return 1;
            else
                return 0;
        }
    };

    int main()
    {
        Department *dp[5]=                      ///department type object declaration
        {
            new Department("CSE"),
            new Department("CSE"),
            new Department("CSE"),
            new Department("CSE"),
            new Department("CSE"),
        };

        Date *dt[4]=                             ///date type object declaration
        {
            new Date(20,8,1996),
            new Date(15,05,1995),
            new Date(13,11,1993),
            new Date(18,02,1983)
        };
        Student *s[3]=                               ///Student type object declaration
        {
            new Student("Abir",dt[0],dp[0],1001,4,301),
            new Student("Atif",dt[1],dp[1],1002,4,400),
            new Student("Araf",dt[2],dp[2],1003,2,200)
        };
        Faculty *f[2]=                                ///faculty object declaration.
        {
            new Faculty("Fahim Ahmed","Professor",dp[3]),
            new Faculty("Jahid Ahmed","Lecturer",dp[4])
        };
        cout<<"THE DETAILS OF FACULTY MEMBER: "<<endl<<endl;
        for(int i=0; i<2; i++){
            f[i]->View_Faculty();
            cout<<endl;
        }
        cout<<endl<<endl;
        cout<<"THE DETAILS OF STUDENTS: "<<endl<<endl;
        for(int i=0; i<3; i++){
            s[i]->View_Student_Info();
            cout<<endl;
        }
        int x;
        cout<<endl<<endl;
        for(int i=0;i<3;i++)
        {
           x=f[i]->select_coach(s[i]);
           if(x==1)
           {
               cout<<"THE STUDENT CAN BE SELECTED AS COACH.."<<endl;
               cout<<"THE DETAILS OF THE STUDENT IS: "<<endl;
               s[i]->View_Student_Info();
               cout<<endl<<endl;
           }
           else
           {
               cout<<"THE STUDENT IS NOT SELECTED AS COACH.."<<endl;
               cout<<"THE DETAILS OF THE STUDENT IS: "<<endl;
               s[i]->View_Student_Info();
               cout<<endl<<endl;
           }
        }
        return 0;
    }
