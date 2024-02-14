


#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int NumOfEmployees();
int TotDaysAbsent(int numbersOfEmployees);
double AverageAbsent(int totDaysAbsent,int numOfEmployees);
ofstream global;

int main()
{
    cout<<"Calculate the average number of days a company's employees are absent"<<endl;
    
    int a=NumOfEmployees();
    int b=TotDaysAbsent(a);//getting b variable as a totalDays/absent
    double c=AverageAbsent(b,a);
    string name="BOA KIM";
    
    global<<"The "<<a<<" employees were absent a total of "<<b<<" days."<<endl;
    global<<"The average number of days absent is "<<fixed<<setprecision(2)<<c<<" days."<<endl;
    global<<"Programmer: "<<name;
    global<<"Due Date:May 11"<<endl;
    
    return 0;
}

//The first funtion's defination for the number of employees.
int NumOfEmployees()
{
    int n;
    cout<<"The number of employess in the company: ";
    cin>>n;
   
    while (n<1)//Do not accept the number less than 1.
   {
       cout<<"Invalid data. Please put the number greater than 1."<<endl;
       cin>>n;
       
   }
    return n;
 }

//The second function's defination
int TotDaysAbsent(int NumbersOfEmployees)
{
    int idNumber=0;
    int missedDays,totDaysAbsent=0;
    
    global.open("EMPLOYEE ABSENCE.txt");//open the file "EMPLOYEE ABESNCE.text.
    for(int a=0;a<NumbersOfEmployees;a++)//Get the id numbers and absent days and write it.
    {
        cout<<"ID number of the Employee(4 digit or less): ";
        cin>>idNumber;
        cout<<"The number of days that the employee missed during the past year: "<<endl;
        cin>>missedDays;
        
        
        while(missedDays<=0)//Do not accept a negative number.
        {
            cout<<"The negative number is invalid.Please input number above 0"<<endl;
            cin>>missedDays;
        }
        
        totDaysAbsent+=missedDays;//accumulating missedDays.
        
        //write them to the file.
        global<<"employee id    days absent"<<endl;
        global<<idNumber<<"             ";//set 4 numbers for id
        global<<missedDays<<endl;
       
       }
      
    return totDaysAbsent;
}

//The third fuction defination.
double AverageAbsent(int totDaysAbsent,int numOfEmployees)
{
  double totalOfAverageAbsent=0.0;
  totalOfAverageAbsent=(double)totDaysAbsent/(double)numOfEmployees;
  
    return totalOfAverageAbsent;
}

