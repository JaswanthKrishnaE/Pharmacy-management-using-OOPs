#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;
//Global declaration of first name and last name
    string arrfn[25]={"Amelia","Beatta","Camille","Dalialah""Evelyn","Fatyma","Garnett",
                    "Harmoni","Ileana","Jainel","Kalidas","Luna","Mahavira","Nartana",
                    "Oliver","Patrick","Quiterie","Raimundo","Scarlett","Teresa",
                    "Ulbrich","Valencia","Wachowicz","Xiang","Yacovone","Zadra"};
    string arrln[25]={"Abella","Batista","Cristina","Devorah""Edith","Franciska","Gorge",
                    "Hermoine","Isebella","Jane","Katrina","Lisbon","Martha","Nick",
                    "O'conner","Priya","Quin","Rregina","Samnatha","Tejaswini",
                    "Urvasi","Varsha","Whitney","Xiang","Yolanda","Zahra"};

/*----------------------------------------------------------------------------------------------- */ 

class symptom
{
private:
    int sNo;
    string symp;

public:
    void menus();
    void inserts();
    void displays();
    void searchs();
    void finds(int i);
    int getsNo(string sy);
};
void symptom::menus()
{
    start:
    int choice;
    char x;
    cout << "\n================================================================================================" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t|       ADDING  SYMPTOMS    |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Symptom" << endl;
    cout << "\t\t\t 2. Display Symptom" << endl;
    cout << "\t\t\t 3. Search Record" << endl;
    cout << "\t\t\t 9. Back" << endl;
    cout << "\t\t\t 0. Exit" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/9/0]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "t\t\tEnter Your Choose: ";
    cin >> choice;
    cout << endl;
    cout << "\t\t\t---------------------------" << endl;
    switch (choice)
    {
    case 1:
    ins:
        inserts();
        cout << "\n\t\t\t Add Another Symptom to database (Y,N): ";
        cin >> x;
        if(x=='y' || x=='Y'){
            goto ins;
        }
       goto start;
        break;
    case 2:
        displays();
       goto start;
        break;
    case 3:
        searchs();
       goto start;
        break;
    case 9:
       // back
        break;        
    case 0:
    exit(0);
        break;
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
   }
   
void symptom::inserts() // add symptom details
{
    fstream file;
    cout << "\n------------------------------------------------------------------------------------------------";
    cout << "\n---------------------------------- Add Symptom Details -----------------------------------------" << endl;
    
    cout << "\t\t\tEnter Serial no.: ";
    cin >> sNo;
    cout << "\t\t\tSymptom: ";
    cin >> symp;
    file.open("symptoms.txt", ios::app | ios::out);
    file << " " << sNo << " " << symp<< "\n";
    file.close();
}

    void symptom::displays() // display symptoms details
    {

    fstream file;
    int total = 1;
    cout << "\n------------------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------- symptom Record Table ----------------------------------------" << endl;
    file.open("symptoms.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {
        file >> sNo >> symp;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t symptom No.: " << total++ << endl;
            cout << "\t\t\tEnter Serial no.: " << sNo << endl;
            cout << "\t\t\t Symptom: " << symp << endl;
            file >> sNo >> symp;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    file.close();
}

    void symptom::searchs() // search data of symptom
    {
    fstream file;
    int found = 0;
    file.open("symptoms.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------" << endl;
        cout << "----------------------------------- symptom Search Data ----------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        int no;
        cout << "\n------------------------------------------------------------------------------------------------";
        cout << "\n---------------------------------- symptom Search Data -----------------------------------------" << endl;
 
        cout << "\n Enter S No. of symptom Which You Want to Search: ";
        cin >> no;
        file >> sNo >> symp;

        while (!file.eof())
        {
            if (sNo == no)
            {
            cout << "\t\t\tEnter Serial no.: " << sNo << endl;
            cout << "\t\t\tSymptom: " << symp << endl;
                found++;
            }
            file >> sNo >> symp;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tsymptom Roll No. Not Found...";
        }
        file.close();
    }
    }

    void symptom::finds(int i){
    fstream file1;
    int no;
        file1.open("symptoms.txt", ios::in);
        no=i;
        file1 >> sNo >> symp;

        while (!file1.eof())
        {
            if (sNo == no)
            {
            cout << "\t\t\tSymptom: " << symp << endl;
            }
            file1 >> sNo >> symp;
        }
        
        file1.close();

    }

    int symptom::getsNo(string sy){
        fstream file1;
        int t;
        file1.open("symptoms.txt", ios::in);
        file1 >> sNo >> symp;

        while (!file1.eof())
        {
            if (symp == sy)
            {
            t=sNo;
            }
            file1 >> sNo >> symp;
        }
        
        file1.close();

            return t;
    }

/*----------------------------------------------------------------------------------------------- */
class person:public symptom
{
    private:
    string firstName;
    string lastName;
    string fullName;
    long long int contactNo;
    int date,d,m,y;
    int ns=0;
    int arrS[38]={0};
    public:
    void Create();
    void Manual();
    void random();
    void MgenerateSD();
    void RgenerateSD();
    void printdata();

    
};
    void person::Create(){
        random();
        for (int i = 0; i < 38; ++i)
        {
            arrS[i]=0;
        }        
        RgenerateSD();
        printdata();
    
    }
    
    void person::random(){
        fstream file;
        firstName=arrfn[rand()%26];
        lastName=arrln[rand()%26];
        fullName = firstName+lastName;
        contactNo=((6+rand()%4)*100000);
        y = 2019+rand()%2;
        m =1+rand()%12;
        if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
        {
        d=1+rand()%31;
        }
        else if(m==2){
        d=1+rand()%27;
        }
        else{
        d=1+rand()%30;
        }
        date = d*1000000+m*10000+y;

    }

    void person::RgenerateSD(){
        //symptoms or disease
        int x= rand()%2;
        x=0;
        int t;
        //if x=0 symptoms
        if(x==0){
        ns=5+rand()%5;
        for (int i = 0; i < ns; ++i)
        {
            t=1+rand()%36;
            arrS[t]=1;
        }
        }
    }
    
void person::printdata(){
    cout << "\t\t\tFirst name :" <<firstName<<endl;
    cout << "\t\t\tLast name :" <<lastName<<endl;
    cout << "\t\t\tFull name :" <<fullName<<endl;
    cout << "\t\t\tContact no. :" <<contactNo<<endl;
    cout << "\t\t\tDate of order :" <<date<<endl;
    //no. of sumptons
    ns=0;
    for (int i = 0; i < 38; ++i)
    {
        if(arrS[i]==1){
            ns++;
        }
    }
    cout << "\t\t\tNo. of symptoms :" <<ns<<endl;
    //print symptoms
    for (int i = 0; i < 38; ++i)
    {
    if (arrS[i]==1){
        finds(i);
    }
    }


    
}

/*----------------------------------------------------------------------------------------------- */ 
class admin
{
public:
//    admin();
    void menu(){
    int option;
    symptom SYMP;
    person pa;
    Start:
    cout << "\n================================================================================================" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t|        IIITs Pharmacy      |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Creating data of Customer" << endl;
    cout << "\t\t\t 2. Medicine data" << endl;
    cout << "\t\t\t 3. Symptoms data " << endl;
    cout << "\t\t\t 9. Back" << endl;
    cout << "\t\t\t 0. Exit" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/9/0]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tEnter Your Choose: ";
    cin >> option ;
    cout << endl;
    cout << "\t\t\t---------------------------" << endl;
    switch (option)
    {
    
    case 1:
    // creating data
    pa.Create();
    goto Start;
    break;

    case 2:
    //tablet data
    goto Start;
    break;    

    case 3:
    //Symptoms data
    SYMP.menus();
    goto Start;
    break;
          

    case 9:
    break;
    
    case 0:
    exit(0);
    break;
    default:
    cout << "\n\t\t\t Invalid choice... Please Try Again..";
    goto Start;
    }
    }
};
/*----------------------------------------------------------------------------------------------- */ 
    class receptionist
    {
    public:
    //    receptionist();
    void menu(){
    int option;
    person pr;
    Start:
    cout << "\n================================================================================================" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t|        IIITs Pharmacy      |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Creating data of Customer" << endl;
    cout << "\t\t\t 2. Medicine data" << endl;
    cout << "\t\t\t 9. Back" << endl;
    cout << "\t\t\t 0. Exit" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/9/0]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tEnter Your Choose: ";
    cin >> option ;
    cout << endl;
    cout << "\t\t\t---------------------------" << endl;
    switch (option)
    {
    
    case 1:
    // creating data
    pr.Create();
    goto Start;
    break;

    case 2:
    //medicine data
    goto Start;
    break;    
       
    case 9:
    //back
    break;
    
    case 0:
    exit(0);
    break;
    default:
    cout << "\n\t\t\t Invalid choice... Please Try Again..";
    goto Start;
    }
    }

};
/*----------------------------------------------------------------------------------------------- */ 
class customer
{
public:
//    customer();
    void menu(){
    int option;
    Start:
    cout << "\n================================================================================================" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t|        IIITs Pharmacy      |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Total Transactions Made" << endl;
    cout << "\t\t\t 2. Latest Transaction" << endl;
    cout << "\t\t\t 9. Back" << endl;
    cout << "\t\t\t 0. Exit" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/9/0]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tEnter Your Choose: ";
    cin >> option ;
    cout << endl;
    cout << "\t\t\t---------------------------" << endl;
    switch (option)
    {
    
    case 1:
//Total Transactions Made
    goto Start;
    break;

    case 2:
//Latest Transaction
    goto Start;
    break;
    
    case 9:
    //back
    break;
    
    case 0:
    exit(0);
    break;
    default:
    cout << "\n\t\t\t Invalid choice... Please Try Again..";
    goto Start;
    }
    }
};
/*----------------------------------------------------------------------------------------------- */ 

int main()
{   
    int option;
    admin a;
    receptionist r;
    customer c;
    //radom generation
    srand(time(NULL));
login:
     cout << "\n================================================================================================" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t|        IIITs Pharmacy      |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Admin" << endl;
    cout << "\t\t\t 2. Receptionist " << endl;
    cout << "\t\t\t 3. Customer" << endl;
    cout << "\t\t\t 0. Exit" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/0]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tEnter Your Choose: ";
    cin >> option ;
    cout << endl;
    cout << "\t\t\t---------------------------" << endl;
    switch (option)
    {
    case 1:
    //admin login
    a.menu();
    break;

    case 2:
    //receptionist login
    r.menu();
    break;
    
    case 3:
    //customer login
    c.menu();
    break;   

    case 0:
    exit(0);
    break;

    default:
    cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    goto login;

    return 0;
}
