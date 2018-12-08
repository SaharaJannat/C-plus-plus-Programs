#include<bits/stdc++.h>
#include<string>
#include <fstream>

using namespace std;

class Person                     ///Person class
{
public:
    Person() {}                 ///Default Constructor
    string name, date_of_birth;
};

class Owner                       ///Owner Class
{
public:
    class Member : public Person        ///Member class inherits Person class
    {
    public:
        void getName(string names, string d_o_birth)
        {
            name = names;
            date_of_birth = d_o_birth;

        }

        class Meal                      ///Meal class
        {
        public:
            static int counter1,counter2;
            float deposit, total_cost, meal_rate;
            int t_meal;
            string cmeal[15],  date[31];

            get_meal(int total_meal, float deposits, float meal_rate)       /// function for Meal information
            {
                total_cost = total_meal * meal_rate;
                deposit = deposits;
                t_meal = total_meal;
                this->meal_rate=meal_rate;
            }

            meal_count(string dates,string meals,int Members)                    ///function for meal counting
            {
                date[counter1] = dates;
                cmeal[counter1] = meals;
                if(counter2 % Members == Members - 1) counter1++;
                counter2++;

            }
        };


        view(int counter,int DayCount)                                          /// function for viewing Meal information
        {
            cout << "Member No :"<< counter << endl;
            cout << "Name : " << name <<endl;
            cout << "Date of Birth : " << date_of_birth <<endl;
            cout << "---------------------------" <<endl;
            cout<< "Total Deposit --> " << ml.deposit << endl;
            cout << "Total meal    --> " << ml.t_meal << endl;
            cout << "Meal Rate     --> " << ml.meal_rate << endl;
            cout << "Total Cost    --> " << ml.total_cost <<  endl;
            cout << "Total Balance --> " << ml.deposit - ml.total_cost << endl<<endl;
            cout << "----Meal Information of " << name << "----\n"<<endl;
            for(int j = 1; j<DayCount; j++) cout << ml.date[j] << " --> " << ml.cmeal[j] <<endl;
            cout << endl<<endl;
            cout << "---------------------------" <<endl;
            cout << "---------------------------" <<endl<<endl<<endl;
        } Meal ml ;
    };
    Member members[15];
};

view_print(int deposite,int shopping,int TotalMeal,float meal_rate,int Members)
{
    cout << endl << "Meal Informations : " << endl;
    cout << "--------------------------------------" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Total Member : " << Members << endl;
    cout << "Total Deposites : "  << deposite << endl;
    cout << "Total Cost : "  << shopping << endl;
    cout << "Total Meal : "  << TotalMeal << endl;
    cout << "Meal Rate : "  << meal_rate << endl;
    cout << "--------------------------------------" << endl;
    cout << "--------------------------------------" << endl << endl;
}
int Owner::Member::Meal :: counter1;                     ///Defination of Static Data Member
int Owner::Member::Meal:: counter2;                          ///Defination of Static Data Member
int main()
{
    Owner owner;


    string name,date_of_birth,deposite,date,cmeal[31][15];
    int counter=0,TotalMeal = 0;

    int DayCount = 0;
    string apps;

    string MeaL[31];
    ifstream file,file_2;

    /***---------------Open csv file for Total Member Counting--------------------***/

    file.open("E:/Arman_Name.csv");
    int MemberCount = 0;

    while(file.good())
    {
        getline(file,name,',');
        getline(file,date_of_birth, ',');
        getline(file,deposite, '\n');
        MemberCount++;

    }
    MemberCount = MemberCount - 1;

    file.close();

    /***---------------Open csv file for Total Day Counting--------------------***/


    file_2.open("E:/Arman_Meal.csv");       ///Open a csv file named meal

    while(file_2.good())                        ///days count (end of the file)
    {
        getline(file_2,date,',');

        for(int mem=0; mem<MemberCount; mem++)
        {
            if(mem==MemberCount - 1) getline(file_2, cmeal[mem][counter], '\n'); ///for last person
            else  getline(file_2, cmeal[mem][counter], ',');
        }     ///others
        DayCount++;
    }
    DayCount = DayCount - 1;

    file_2.close();


    int total[DayCount]= {0};

    /***---------------Open csv file for Total Meal Counting--------------------***/

    file_2.open("E:/Arman_Meal.csv");       ///Open a csv file named meal

    /// while(file_2.good())                        ///days count (end of the file)
    for(int i = 0; i<DayCount; i++)
    {
        getline(file_2,date,',');

        for(int mem=0; mem<MemberCount; mem++)
        {
            if(mem==MemberCount - 1) getline(file_2, cmeal[mem][counter], '\n'); ///for person 6
            else  getline(file_2, cmeal[mem][counter], ',');         ///others

            for(int i=0; i<DayCount; i++)
                if(counter == i) MeaL[i] = cmeal[mem][counter];

            int DayTMeal[DayCount];
            int num[DayCount];
            memset(DayTMeal, 0, sizeof(DayTMeal));
            memset(num, 0, sizeof(num));
            for(int i = 0; i<DayCount; i++)
            {
                if(counter != i)
                    continue;
                if(counter == i)
                {
                    for(int j=0; MeaL[i][j]; j++)
                    {
                        if(MeaL[i][j]>='0' and MeaL[i][j]<='9')
                        {
                            num[i] *= 10;
                            num[i] += (MeaL[i][j]-'0');
                        }
                        else
                        {
                            DayTMeal[i] += num[i];
                            num[i] = 0;
                        }
                    }
                    DayTMeal[i] += num[i];
                }
                else DayTMeal[i] = 0;
            }

            for(int i=0; i<MemberCount; i++)
            {
                if(mem == i )
                {
                    for(int j=0; j<DayCount; j++)          /// individual meal count
                        total[i] += DayTMeal[j];
                }
            }

            owner.members[mem].ml.meal_count(date,cmeal[mem][counter],MemberCount);
        }
        counter++;
    }

    file_2.close();              ///file closed (meal)

    ifstream bz;
    string baz;
    int shopping =0,m;
    bz.open("E:/Arman_Shopping.csv");                                        ///Open a csv file named bazar

    while(bz.good())
    {
        getline(bz, baz,'\n');
        stringstream gerk(baz);
        gerk >> m;
        shopping += m;
    }
    shopping = shopping - m;

    for(int i=0; i<MemberCount; i++)
        TotalMeal += total[i];

    bz.close();
    float meal_rate = shopping / (float)TotalMeal;


    file.open("E:/Arman_Name.csv");
    ///Open a csv file named "name"

    int deposites = 0,n;
    string Name[MemberCount];
    for(int i = 0; i<MemberCount; i++)
    {
        float final_dep = 0.0;
        getline(file,name,',');
        getline(file,date_of_birth, ',');
        getline(file,deposite, '\n');

        stringstream geek(deposite);                                    ///converts strings into integer
        geek >> final_dep;
        deposites += final_dep;
        Name[i] = name;
        owner.members[i].getName(name,date_of_birth);
        owner.members[i].ml.get_meal(total[i],final_dep,meal_rate);

    }
    file.close();                             ///file closed (name)
//cout << name << endl;
    string password = "123456";
    string getpassword;

//cin >> getpassword;
    while(true)
    {
        cout << "Please enter your Password : " ;
        cin >> getpassword;
        if(password == getpassword)
        {
            view_print(deposites,shopping,TotalMeal,meal_rate,MemberCount); ///overall meal info
            break;
        }
        else cout << endl << "Your password is incorrect,please try again." << endl << endl;
    }
    string NameUpper[MemberCount],NameLower[MemberCount];



    while(true)
    {

        string person;
        cout << "Enter Member Name : " << endl;
        cin >> person;
        for(int i = 0; i<person.size(); i++)
        {
            if(i == 0) person[i]=toupper(person[i]);
            else person[i]=tolower(person[i]);
        }
        int y;
        //                 ///individual meal info show
        for(int i = 0; i<MemberCount; i++)
        {
            if(person == Name[i])
            {
                y = i;
                cout << endl << "Mess Members Information :" << endl << endl;
                owner.members[y].view(y+1,DayCount);
                break;
            }
        }

    }
    return 0;
}
