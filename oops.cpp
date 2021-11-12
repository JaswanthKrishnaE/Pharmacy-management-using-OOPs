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
    void menu();
    void insert();
    void display();
    void search();
};
void symptom::menu()
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
        insert();
       goto start;
        break;
    case 2:
        display();
       goto start;
        break;
    case 3:
        search();
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
   
void symptom::insert() // add symptom details
{
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Symptom Details ---------------------------------------------" << endl;
    
    cout << "\t\t\tEnter Serial no.: ";
    cin >> sNo;
    cout << "\t\t\t Symptom: ";
    cin >> symp;
    file.open("symptoms.txt", ios::app | ios::out);
    file << " " << sNo << " " << symp<< "\n";
    file.close();
}

void symptom::display() // display symptoms details
{

    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- symptom Record Table --------------------------------------------" << endl;
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

void symptom::search() // search data of symptom
{
    fstream file;
    int found = 0;
    file.open("symptoms.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- symptom Search Data ------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        int no;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- symptom Search Data ------------------------------------------" << endl;
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
    cout << "search "<< endl;
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
    void menu();
    void insert();
    void display();
    void search();
    
};
void disease::menu()
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
        insert();
        cout << "\n\t\t\t Add Another Student Record (Y,N): ";
        cin >> x;
        if(x=='y' || x=='Y'){
            goto ins;
        }
        goto start;
        break;
    case 2:
        display();
    goto start;
        break;
    case 3:
        search();
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

   void disease::insert() // add symptom details
{
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Disease Details ---------------------------------------------" << endl;
    
    cout << "\t\t\tEnter Serial no.: ";
    cin >> dNo;
    cout << "\t\t\t Disease: ";
    cin >> dis;
    file.open("diseases.txt", ios::app | ios::out);
    file << " " << dNo << " " << dis<< "\n";
    file.close();
}

void disease::display() // display symptoms details
{

    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- symptom Record Table --------------------------------------------" << endl;
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
void disease::search() // search data of symptom
{
    fstream file;
    int found = 0;
    file.open("diseases.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Disease Search Data ------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        int no;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Disease Search Data ------------------------------------------" << endl;
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
    cout << "search "<< endl;
}
/*----------------------------------------------------------------------------------------------- */
/*
class createManual
{
private:
    string fName;
    string lName;
    long int cNo;
    int da,mo,ye;    
public:
//    createManual();
    void manualInput();
    void gendate();  
};
void createManual::manualInput(){
    cout << "\t\tEnter the First name :" << endl;
    cin>>fName;
    cout << "\t\tEnter the Last name :"<< endl;
    cin >> lName;
    cout << "\t\tEnter the Contact Number :"<< endl;
    cin >> cNo;
    cout << "\t\tEnter the date of order :"<< endl;
    cin >> da>>mo>>ye;
}
*/

/*----------------------------------------------------------------------------------------------- */
class person
{
private:
    string firstName;
    string lastName;
    string fullName;
    long long int contactNo;
    int date,d,m,y;
    int arrS[30]={0};
    int arrD[20]={0};

public:
//    create();
    void menu();
    void Manual();
    void random();
    
};
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
       goto data;
        break;
    case 2:
        random();
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
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Customer Details ---------------------------------------------" << endl;

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
    file.open("draft.txt", ios::app | ios::out);
    file << " " << firstName << " " << lastName<< " " << fullName<< " " <<contactNo << " " << d << " " << m << " " << y <<" " << date<< "\n";
    file.close();

}
void person::random(){
    fstream file;
    firstName=arrfn[rand()%26];
    lastName=arrln[rand()%26];
    fullName = firstName+lastName;
    contactNo=((6+rand()%4)*1000000000);
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
    file.open("draft.txt", ios::app | ios::out);
    file << " " << firstName << " " << lastName<< " " << fullName<< " " <<contactNo << " " << d << " " << m << " " << y <<" " << date<< "\n";
    file.close();

}
/*----------------------------------------------------------------------------------------------- */ 
    //initializing all classes
    symptom SYMP;
    disease DIS;
    person p;
void admin(){
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
    SYMP.menu();
    goto Start;
        break;
    case 4:
    // Diseases data
    DIS.menu();
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

int main()
{   
    int option;
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
    //admin usage
    admin();
    break;

    case 2:
    //receptionist usage
    break;
    
    case 3:
    //customer login
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
