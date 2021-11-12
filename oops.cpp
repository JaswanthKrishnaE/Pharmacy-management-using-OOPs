#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

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
    cout << "Enter Your Choose: ";
    cin >> choice;

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
    cout << "\t\t\t Symptom: ";
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
            cout << "\t\t\t Symptom: " << symp << endl;
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
/*----------------------------------------------------------------------------------------------- */ 
//class disease
class disease
{
private:
    int dNo;
    string dis;    
public:
//  disease();
    void menud();
    void insertd();
    void displayd();
    void searchd();
    void findd(int i);
    
};
void disease::menud()
{
    int choice;
    char x;
    start:
    cout << "\n================================================================================================" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t|       ADDING  DISEASE    |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter New Disease" << endl;
    cout << "\t\t\t 2. Display Diseases" << endl;
    cout << "\t\t\t 3. Search Disease" << endl;
    cout << "\t\t\t 9. Back" << endl;
    cout << "\t\t\t 0. Exit" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/9/0]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    ins:
        insertd();
        cout << "\n\t\t\t Add Another Disease to database (Y,N): ";
        cin >> x;
        if(x=='y' || x=='Y'){
            goto ins;
        }
        goto start;
        break;
    case 2:
        displayd();
    goto start;
        break;
    case 3:
        searchd();
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

   void disease::insertd() // add symptom details
{
    fstream file;
    cout << "\n------------------------------------------------------------------------------------------------";
    cout << "\n---------------------------------- Add Disease Details -----------------------------------------" << endl;
    
    cout << "\t\t\tEnter Serial no.: ";
    cin >> dNo;
    cout << "\t\t\t Disease: ";
    cin >> dis;
    file.open("diseases.txt", ios::app | ios::out);
    file << " " << dNo << " " << dis<< "\n";
    file.close();
}

void disease::displayd() // display symptoms details
{

    fstream file;
    int total = 1;
    cout << "\n------------------------------------------------------------------------------------------------";
    cout << "\n----------------------------------    Disease  Data    -----------------------------------------" << endl;

    file.open("diseases.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {
        file >> dNo >> dis;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t Disease No.: " << total++ << endl;
            cout << "\t\t\tEnter Serial no.: " << dNo << endl;
            cout << "\t\t\tDisease: " << dis << endl;
            file >> dNo >> dis;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }
    file.close();
}
void disease::searchd() // search data of symptom
{
    fstream file;
    int found = 0;
    file.open("diseases.txt", ios::in);
    if (!file)
    {
        cout << "\n------------------------------------------------------------------------------------------------";
        cout << "\n---------------------------------- Disease Search Data -----------------------------------------" << endl;

        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        int no;
        cout << "\n------------------------------------------------------------------------------------------------";
        cout << "\n---------------------------------- Disease Search Data -----------------------------------------" << endl;

        cout << "\n Enter S No. of Disease Which You Want to Search: ";
        cin >> no;
        file >> dNo >> dis;

        while (!file.eof())
        {
            if (dNo == no)
            {
            cout << "\t\t\tEnter Serial no.: " << dNo << endl;
            cout << "\t\t\tDisease: " << dis << endl;
                found++;
            }
            file >> dNo >> dis;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tsymptom Roll No. Not Found...";
        }
        file.close();
    }

}
void disease::findd(int i){
    int no;
    fstream file2;
    file2.open("diseases.txt", ios::in);
    no=i;
    file2 >> dNo >> dis;
        while (!file2.eof())
        {
            if (dNo == no)
            {
            cout << "\t\t\tDisease: " << dis << endl;
            }
            file2 >> dNo >> dis;
        }
        file2.close();
        

}
/*----------------------------------------------------------------------------------------------- */ 
    //initializing all classes
    symptom SYMP;
    disease DIS;

/*----------------------------------------------------------------------------------------------- */
class person:public symptom,public disease
{
private:
    string firstName;
    string lastName;
    string fullName;
    long long int contactNo;
    int date,d,m,y;
    int ns=0,nd=0;
    int arrS[11]={0};
    int arrD[2]={0};

public:
//    create();
    void menu();
    void Manual();
    void random();
    void MgenerateSD();
    void RgenerateSD();
    void printdata();

    
};
void person::MgenerateSD(){
    int choice;
    char x;
    data:
    cout << "\n================================================================================================" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t|  ADD SYMPTOMS OR DISEASE  |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Symptom" << endl;
    cout << "\t\t\t 2. Disease" << endl;
    cout << "\t\t\t 9. Back" << endl;
    cout << "\t\t\t 0. Exit" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/9/0]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
       goto data;
        break;
    case 2:
    goto data;
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

void person::RgenerateSD(){
    //symptoms or disease
    int x= rand()%2;
    int t;
    //if x=0 symptoms
    //if x=1 disease
    if(x==0){
        ns=2+rand()%5;
        for (int i = 0; i < ns; ++i)
        {
            t=1+rand()%10;
            arrS[t]=1;
        }
    }
    if(x==1){
             nd=1+rand()%2;
        for (int i = 0; i < nd; ++i)
        {
            t=1+rand()%2;
            arrD[t]=1;
        }  
    }

}
void person::menu(){
    int choice;
    char x;
    data:
    cout << "\n================================================================================================" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t|         CREATE DATA        |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter manually" << endl;
    cout << "\t\t\t 2. Random generation" << endl;
    cout << "\t\t\t 9. Back" << endl;
    cout << "\t\t\t 0. Exit" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/9/0]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        Manual();
        for (int i = 0; i < 11; ++i)
        {
            arrS[i]=0;
        }        
        for (int i = 0; i < 2; ++i)
        {
            arrD[i]=0;
        }
        MgenerateSD();
        printdata();
        goto data;
        break;
    case 2:
        random();
       for (int i = 0; i < 11; ++i)
        {
            arrS[i]=0;
        }        
        for (int i = 0; i < 3; ++i)
        {
            arrD[i]=0;
        }
        RgenerateSD();
        printdata();
    goto data;
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
void person::Manual(){
    fstream file;
    cout << "\n------------------------------------------------------------------------------------------------";
    cout << "\n--------------------------------- Add Customer Details -----------------------------------------" << endl;

    cout << "\t\tEnter the First name :" << endl;
    cin>>firstName;
    cout << "\t\tEnter the Last name :"<< endl;
    cin >> lastName;
    cout << "\t\tEnter the Contact Number :"<< endl;
    cin >> contactNo;
    cout << "\t\tEnter the date of approach[dd] :"<< endl;
    cin >> d;
    cout << "\t\tEnter the date of approach[mm] :"<< endl;
    cin >> m;
    cout << "\t\tEnter the date of approach[yyyy] :"<< endl;
    cin >> y;

    fullName = firstName+lastName;
    date = d*1000000+m*10000+y;


}
void person::random(){
    fstream file;
    firstName=arrfn[rand()%26];
    lastName=arrln[rand()%26];
    fullName = firstName+lastName;
    contactNo=((6+rand()%4)*100000);
    y = 2019+rand()%2;
    m =rand()%13;
    if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
        d=rand()%32;
    }
    else if(m==2){
        d=rand()%28;
    }
    else{
        d=rand()%31;
    }
    date = d*1000000+m*10000+y;

}
void person::printdata(){
    int found=0;
    int no;
    cout << "First name :" <<firstName<<endl;
    cout << "Last name :" <<lastName<<endl;
    cout << "Full name :" <<fullName<<endl;
    cout << "Contact no. :" <<contactNo<<endl;
    cout << "Date of order :" <<date<<endl;
    //print symptoms
    for (int i = 0; i < 11; ++i)
    {
    if (arrS[i]==1){
        finds(i);
    }
    }

    //print disease
    for (int i = 0; i < 3; ++i)
    {
        if (arrD[i]==1){
        findd(i);
    }
    }
}

    person p;
/*----------------------------------------------------------------------------------------------- */ 
class admin
{
public:
//    admin();
    void menu(){
    int option;
    Start:
    cout << "\n================================================================================================" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t|        IIITs Pharmacy      |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Creating data of Customer" << endl;
    cout << "\t\t\t 2. Medicine data" << endl;
    cout << "\t\t\t 3. Symptoms data " << endl;
    cout << "\t\t\t 4. Disease data" << endl;
    cout << "\t\t\t 9. Back" << endl;
    cout << "\t\t\t 0. Exit" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/9/0]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> option ;
    switch (option)
    {
    
    case 1:
    // creating data
    p.menu();
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
    
    case 4:
    // Diseases data
    DIS.menud();
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
    cout << "Enter Your Choose: ";
    cin >> option ;
    switch (option)
    {
    
    case 1:
    // creating data
    p.menu();
    goto Start;
    break;

    case 2:
    //tablet data
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
    cout << "\t\t\t 3. All Transaction" << endl;
    cout << "\t\t\t 9. Back" << endl;
    cout << "\t\t\t 0. Exit" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/9/0]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> option ;
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

    case 3:
//All Transaction
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
    cout << "Enter Your Choose: ";
    cin >> option ;
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
