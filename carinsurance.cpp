#include <iostream>
#include <string>
using namespace std;

class Details
{
    int rgno,rta,seat,manu,chasis;
    long int engine;
public:
    void get()
    {
        cout<<"Enter registration number:";
        cin>>rgno;
        cout<<"Enter RTA number:";
        cin>>rta;
        cout<<"Enter chasis number:";
        cin>>chasis;
        cout<<"Enter seat capacity:";
        cin>>seat;
        cout<<"Enter engine number:";
        cin>>engine;
        cout<<"Enter manufacture year:";
        cin>>manu;
    }
    void print()
    {
        cout<<"Registration number:"<<rgno;
        cout<<"Rta number:"<<rta;
        cout<<"Chasis number:"<<chasis;
        cout<<"Seat capacity:"<<seat;
        cout<<"Engine number:"<<engine;
        cout<<"Manufacture year:"<<manu;
    }
};

class Car
{
private:
    string make;
    string model;
    int year;


public:
        Car(string mk="", string md="", int yr=0) {
           this-> make = mk;
           this-> model = md;
           this-> year = yr;
        }
        inline
        void setMake(string mk) {
            make = mk;
        }
        inline
        void setModel(string md) {
            model = md;
        }
        inline
        void setYear(int yr) {
            year = yr;
        }

        string getMake() const {
            return make;
        }
        string getModel() const {
            return model;
        }
        int getYear() const {
            return year;
        }

        void print() const {
            cout <<"Car make   :"<< make << " " <<endl<<endl<<"Car model    :"<< model << "  " <<endl;
            cout << endl;
            cout <<"Registration year     :"<< year << "  " << endl;
            cout <<endl;
        }
};

class Driver:public Car
 {
    private:
        string name;
        int age;
        Car car;

    public:
        Driver(string nm="", int ag=0, string mk="", string md="", int yr=0)
        {
            name = nm;
            age = ag;
            car.setMake(mk);
            car.setModel(md);
            car.setYear(yr);
        }
        inline
        void setName(string nm)
        {
            name = nm;
        }
        inline
        void setAge(int ag)
        {
            age = ag;
        }
        inline
        void setCar(Car c) {
            car = c;
        }

        string getName() const {
            return name;
        }
        int getAge() const {
            return age;
        }
        Car getCar() const {
            return car;
        }

        void print() const
        {
            cout << endl;
            cout << "**** POLICY INFORMATION ****" ;
            cout << endl;
            cout << endl;
            cout << "Driver name :" <<name << " " <<endl<<endl<<"Age         :"<< age << " years old " << endl;
            cout << endl;
            car.print();
        }
};

class Policy
{
private:
        Driver driver;
        int policyNumber;
        double premium;

    public:
        Policy(Driver dr=Driver(), int pn=0, double pr=0.0) {
          this->  driver = dr;
          this->  policyNumber = pn;
          this->  premium = pr;
        }

        void setDriver(Driver dr) {
            driver = dr;
        }
        void setPolicyNumber(int pn) {
            policyNumber = pn;
        }
        void setPremium(double pr) {
            premium = pr;
        }

        Driver getDriver() const {
            return driver;
        }
        int getPolicyNumber() const {
            return policyNumber;
        }
        double getPremium() const {
            return premium;
        }

        void print() const
        {
            cout << "Policy #" << policyNumber <<endl<<endl<< "     Premium: $" << premium << endl;
            driver.print();
        }
};

int main()
{
    Details d;
    Policy policies[10];
    int numPolicies = 0;
    cout<<endl;
    int choice;

    do
    {
    cout << "*********************" << endl;
    cout << "Select an option:" << endl;
    cout << "1. Add a new policy" << endl;

    cout << "2. View all policies" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << "*********************" << endl;
    cout <<endl;

    switch (choice)
    {
    case 1:
    {
    string name, make, model;
    int year;
    int age, policyNumber;
    double premium;
    cout << "Enter driver name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter driver age: ";
    cin >> age;
    cout << "Enter car make: ";
    cin >> make;
    cout << "Enter car model: ";
    cin >> model;
    cout << "Enter car year: ";
    cin>> year;
    cout << "Enter policy number: ";
    cin >> policyNumber;
    cout << "Enter premium: $";
    cin >> premium;
    d.get();
    Car car(make, model, year);
    Driver driver(name, age, make, model, year);
    Policy policy(driver, policyNumber, premium);
    policies[numPolicies] = policy;
    numPolicies++;
    cout <<endl;
    cout << "Policy added successfully!" << endl;
    break;
    }
    case 2:
    {
    if (numPolicies == 0)
    {
        cout << "No policies found!" << endl;
    }
    else
    {
        for (int i = 0; i < numPolicies; i++)
        {
            policies[i].print();
            cout << endl;
            d.print();
        }
    }
    break;
    }
    case 3:
    {
    cout << " **** Thank you for creating an insurance policy ****" << endl;
    cout << endl;
    cout << "   ******* Your welfare is our responsibility *******";
    cout<<endl;
    cout<<endl;
    break;
    }
    default:
    {
    cout << "Invalid choice. Please try again." << endl;
    break;
    }
    }
}
while (choice != 3);

return 0;
}
