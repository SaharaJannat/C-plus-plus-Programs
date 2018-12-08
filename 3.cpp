#include<iostream>
#include<math.h>
#include<fstream>                               // read and write on file.
using namespace std;
class Person
{
protected:
    string name;
    int n_id;
public:
    Person(){}
    Person(string name,int n_id)
    {
        this->name=name;
        this->n_id=n_id;
    }
};
class Driver: public Person
{
    int mobile_number;
    string current_location;

public:
    double lat;
    double lng;
   Driver (){};
    Driver(string name,int n_id,int mobile_number,string current_location,double lat,double lng):Person(name,n_id)
    {
        this->mobile_number=mobile_number;
       this-> current_location=current_location;
       this-> lat=lat;
       this-> lng=lng;
    }
     void driverfile ()
    {
        ofstream myfile2; /// Write in text file same folder.
         myfile2.open ("Driver Information.txt");
        myfile2<<"\nDriver Details "<<endl;
        myfile2<<"-------------------------------"<<endl;
        myfile2<<"Mobile number :"<<mobile_number<<endl;
        myfile2<<"current location   : "<<current_location<<endl;
        myfile2<<"Latitude :"<<lat<<"  degree "<<endl;
        myfile2<<"Longitude :  "<<lng<<" degree "<<endl;
        myfile2<<"Name          :"<<name<<endl;
        myfile2<<"National id   :"<<n_id<<endl;
        myfile2<<"--------------------------------";
        myfile2.close();
    }
    void booking ()
    {
        cout<<"a seat has been confirmed"<<endl;
    }
};
class Uber
{
    Driver driver1,driver2;
public:
    void driver_list(Driver &driver1,Driver &driver2)
    {
       this-> driver1=driver1;
       this-> driver2=driver2;
    }
    double calculate_distance( double customer_lat, double customer_lng, double driver_lat, double driver_lng )
{
    int nRadius = 6371;

    double nDLat = (driver_lat - customer_lat) * (M_PI/180);
    double nDLon = (driver_lng-customer_lng) * (M_PI/180);

        double nA = pow ( sin(nDLat/2), 2 ) + cos(customer_lat) * cos(driver_lat) * pow ( sin(nDLon/2), 2 );

    double nC = 2 * atan2( sqrt(nA), sqrt( 1 - nA ));
    double distance = nRadius * nC;

    return distance;
}

    void contact_with_driver(double customer_lat,double customer_lng)
    {
        double distancefromdriver1,distancefromdriver2;

     distancefromdriver1=calculate_distance(customer_lat,customer_lng,driver1.lat,driver1.lng);
     distancefromdriver2=calculate_distance(customer_lat,customer_lng,driver2.lat,driver2.lng);

     if(distancefromdriver1<distancefromdriver2)
         driver1.booking();
     else
         driver2.booking();
    }
};
class Customer:public Person
{
    int mobile_number;
    string destination;
    double lat;
    double lng;
public:
    Customer(){}
    Customer(string name,int n_id,int mobile_number,string destination,double lat,double lng):Person(name,n_id)
    {
       this-> mobile_number=mobile_number;
        this->destination=destination;
       this-> lat=lat;
       this-> lng=lng;
    }
        friend class Uber;
    void customerfile ()
    {
        ofstream myfile1; /// Write in text file in same folder.
    myfile1.open ("Customer Information.txt");
    myfile1<<"\nCustomer Details "<<endl;
    myfile1<<"----------------------------"<<endl;
    myfile1<<"Mobile number :"<<mobile_number<<endl;
    myfile1<<"Latitude :"<<lat<<"  degree "<<endl;
    myfile1<<"Longitude:  "<<lng<<" degree "<<endl;
    myfile1<<"Destination   :  "<<destination<<endl;
    myfile1<<"Name          :"<<name<<endl;
    myfile1<<"National id   :"<<n_id<<endl;
    myfile1<<"----------------------------"<<endl;
    }
    void contact_with_uber(Uber &uber)
    {
        double lat,lng;
       this-> lat=lat;
       this-> lng=lng;
        cout<<"\n\nFor customer "<<this->name<<", whose Destination is  "<<this->destination<<", "; /// Print in console.

       uber .contact_with_driver(lat,lng);
    }

};
int main()
{
    Customer customer("Abir",1,2345,"Comilla",23,91);

    Driver driver1("Asif",2,72567,"Comilla",21,93);
    Driver driver2("Arif",3,8652,"Feni",22,91);

    driver1.driverfile();
    customer.customerfile();

    Uber uber;
    uber.driver_list(driver1,driver2);

    customer.contact_with_uber(uber);
}
