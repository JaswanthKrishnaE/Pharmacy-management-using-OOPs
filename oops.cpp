#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
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
    cout << "\t\t\t 4. Back" << endl;
    cout << "\t\t\t 5. Exit" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4]" << endl;
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
    case 4:
       // back
        break;        
    case 5:
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
    cout << "\t\t\t 4. Back" << endl;
    cout << "\t\t\t 5. Exit" << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5]" << endl;
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
    case 4:
       // back
        break;
    case 5:
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

int main()
{   
    int option;
    symptom SYMP;
    disease DIS;
Start:
    cout << "\n================================================================================================" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t|        IIITs Pharmacy      |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Creating data of Customer" << endl;
    cout << "\t\t\t 2. Symptoms data " << endl;
    cout << "\t\t\t 3. Disease data" << endl;
    cout << "\t\t\t 4. Medicine data" << endl;
    cout << "\t\t\t 5. Login" << endl;
    cout << "\t\t\t 6. Exit" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> option ;
    switch (option)
    {
    case 1:
// creating data

    break;
    case 2:
    //Symptoms data
    SYMP.menu();
        break;
    case 3:
    // Diseases data
    DIS.menu();
        break;        
    case 4:
    //tablet data
        break;
    case 5:
    //login
        break;   
    case 6:
        exit(0);
        break;
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    goto Start;
    return 0;
}
