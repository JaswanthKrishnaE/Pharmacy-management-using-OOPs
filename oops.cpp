#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Medicine.cpp"
static int n = 4176;

using namespace std;
// Global declaration of first name and last name
string arrfn[26] = {"Amelia", "Beatta", "Camille", "Dalialah", "Evelyn",
                    "Fatyma", "Garnett", "Harmoni", "Ileana", "Jainel", "Kalidas", "Luna",
                    "Mahavira", "Nartana", "Oliver", "Patrick", "Quiterie", "Raimundo",
                    "Scarlett", "Teresa", "Ulnrich", "Valencia", "Wachowicz", "Xiang", "Yacovone", "Zadra"};
string arrln[26] = {"Abella", "Batista", "Cristina", "Devorah", "Edith",
                    "Franciska", "Gorge", "Hermoine", "Isebella", "Jane",
                    "Katrina", "Lisbon", "Martha", "Nick", "O'conner", "Priya",
                    "Quin", "Rregina", "Samnatha", "Tejaswini", "Urvasi", "Varsha",
                    "Whitney", "Xiang", "Yolanda", "Zahra"};

/*----------------------------------------------------------------------------------------------- */

class symptom
{
protected:
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
    cout << "\n\t\t\tEnter Your Choose: ";
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
        if (x == 'y' || x == 'Y')
        {
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
    file << " " << sNo << " " << symp << "\n";
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

        cout << "\n\t\t\t--------------------------";
        cout << "\n\t\t\t|"
             << "SNo"
             << "|"
             << "       Symptom      "
             << "|";
        cout << "\n\t\t\t--------------------------";

        while (!file.eof())
        { /*
             cout << "\n\n\t\t\t symptom No.: " << total++ << endl;
             cout << "\t\t\tEnter Serial no.: " << sNo << endl;
             cout << "\t\t\t Symptom: " << symp << endl;*/
            cout << "\n\t\t\t";
            cout << "|" << setw(3) << sNo;
            cout << "|" << setw(20) << symp;
            cout << "|";

            file >> sNo >> symp;
        }
        cout << "\n\t\t\t--------------------------\n";

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

        cout << "\n\t\t\t--------------------------";
        cout << "\n\t\t\t|"
             << "SNo"
             << "|"
             << "       Symptom      "
             << "|";
        cout << "\n\t\t\t--------------------------";

        while (!file.eof())
        {
            if (sNo == no)
            {
                cout << "\n\t\t\t";
                cout << "|" << setw(3) << sNo;
                cout << "|" << setw(20) << symp;
                cout << "|";

                found++;
            }

            file >> sNo >> symp;
        }
        cout << "\n\t\t\t--------------------------\n";

        if (found == 0)
        {
            cout << "\n\t\t\tsymptom  No. Not Found...";
        }
        file.close();
    }
}

void symptom::finds(int i)
{
    fstream file1;
    int no;
    file1.open("symptoms.txt", ios::in);
    no = i;
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

int symptom::getsNo(string sy)
{
    fstream file1;
    int t;
    file1.open("symptoms.txt", ios::in);
    file1 >> sNo >> symp;

    while (!file1.eof())
    {
        if (symp == sy)
        {
            t = sNo;
        }
        file1 >> sNo >> symp;
    }

    file1.close();

    return t;
}
/*----------------------------------------------------------------------------------------------- */

class Billing : public symptom
{
private:
    string medicine;
    int mrp;

public:
    void gen_med(int l, string sy[], string med[], int i, int mrps[]);
    int generate_bill(string med[], int qty[], int x, int mrps[]);
    void genMed(int l, string med[], int i, int mrps[]);
};
void Billing::genMed(int l, string med[], int i, int mrps[])
{
    fstream file1;
    // int no;
    file1.open("symp_med_mrp.txt", ios::in);
    // no=i;
    file1 >> sNo >> symp >> medicine >> mrp;

    while (!file1.eof())
    {
        if (sNo == l)
        {
            med[i] = medicine;
            mrps[i] = mrp;
        }
        file1 >> sNo >> symp >> medicine >> mrp;
    }

    file1.close();
}

void Billing::gen_med(int l, string sy[], string med[], int i, int mrps[])
{
    fstream file1;
    // int no;
    file1.open("symp_med_mrp.txt", ios::in);
    // no=i;
    file1 >> sNo >> symp >> medicine >> mrp;

    while (!file1.eof())
    {
        if (sNo == l)
        {
            sy[i] = symp;
            med[i] = medicine;
            mrps[i] = mrp;
        }
        file1 >> sNo >> symp >> medicine >> mrp;
    }

    file1.close();
}

int Billing ::generate_bill(string med[], int qty[], int x, int mrps[])
{
    float tot[x], rate[x], total = 0;
    // cout<<"__________________________________________________________________________________________________"<<endl;//98
    // cout<<"*************************************#Generating Bill#********************************************"<<endl;
    // cout<<"__________________________________________________________________________________________________\n\n";
    cout << " __________________________________________________________________________________________________" << endl;
    cout << "|" << setw(99) << "|" << endl;
    cout << "|                                          IIITS PHARMACY                                          |" << endl; // 99
    cout << "|                             near XXX Bank,main road,Sricity,Chittoor                             |" << endl;
    cout << "|                      Contact Info:9347246185,8436542840;state: Andhra Pradesh                    |" << endl;
    cout << "|" << setw(92) << "BillNo:JH000/" << n++ << "/ |" << endl;
    // date
    cout << "|                                        GST INVOICE                                               |" << endl;
    cout << "|__________________________________________________________________________________________________|\n";
    cout << "|" << setw(25) << " |" << setw(13) << " |" << setw(13) << " |" << setw(16) << " |" << setw(16) << " |" << setw(16) << " |" << endl;
    cout << "|" << setw(25) << "Product Name |" << setw(13) << "Qty   |" << setw(13) << "MRP   |" << setw(16) << "Rate  |" << setw(16) << "GST  |" << setw(16) << "Total   |" << endl;
    cout << "|________________________|____________|____________|_______________|_______________|_______________|\n";
    for (int i = 0; i < x; i++)
    {
        rate[i] = (mrps[i] / 10.0) * qty[i];
        tot[i] = rate[i] + (18 * rate[i]) / 100; // 18 percent gst
        total += tot[i];
        cout << "|" << setw(25) << " |" << setw(13) << " |" << setw(13) << " |" << setw(16) << " |" << setw(16) << " |" << setw(16) << " |" << endl;
        cout << "|" << setw(23) << med[i] << " |" << setw(11) << qty[i] << " |" << setw(11) << mrps[i] << " |" << setw(14) << rate[i] << " |" << setw(14) << (18 * rate[i]) / 100 << " |" << setw(14) << tot[i] << " |" << endl;
        // cout<<"|"<<setw(25)<<" |"<<setw(13)<<" |"<<setw(13)<<" |"<<setw(16)<<" |"<<setw(16)<<" |"<<setw(16)<<" |"<<endl;
    }
    cout << "|________________________|____________|____________|_______________|_______________|_______________|\n";
    cout << "|" << setw(99) << "|" << endl;
    cout << "|" << setw(90) << "Total amount: Rs."; //<<total
    printf("%.2f", total);
    cout << "  |" << endl;
    cout << "|__________________________________________________________________________________________________|\n";
    return total;
}

/*----------------------------------------------------------------------------------------------- */
class person : public symptom
{
protected:
    string firstName;
    string lastName;
    string fullName;
    int date, d, m, y;
    int amt = 0;

public:
    int prescriptiom; // 0 or 1
    string getFullName();
    string getFirstName();
    string getLastName();
    void Create();
    void random();
    void printdata();
    void transcount();
    void last5();
    void lasttrans();
    void showTransactionData();
    void showTransactionBydate();
};
string person::getFullName()
{
    return fullName;
}
string person::getFirstName()
{
    return firstName;
}
string person ::getLastName()
{
    return lastName;
}
static int cNo = 1;
void person::Create()
{
    random();

    printdata(); // remove
    prescriptiom = rand() % 2;
    //
    if (prescriptiom == 1)
    {
        cout << "Pharmacy: Do you have a prescription??" << endl;
        cout << "Person: yes sir!  " << endl;
        int k = 0; // k=0 => no prescrption; k=1 => have prescription
        int x = 3 + rand() % (5 - 2 + 1);
        string med[x];
        Billing b;
        int mrps[x], qty[x];
        for (int i = 0; i < x; i++)
        {
            b.genMed(1 + rand() % (total - 1 + 1), med, i, mrps);
            qty[i] = 3 + rand() % (10 - 3 + 1);
        }
        cout << "medicines in prescriptiom are :";
        for (int i = 0; i < x; i++)
        {
            cout << med[i];
            Medicine ut;
            ut.updateStock(med[i], qty[i]);
            if (i != x - 1)
                cout << ", ";
        }
        cout << endl;
        amt = b.generate_bill(med, qty, x, mrps);
    }

    if (prescriptiom == 0)
    {
        int x = 3 + rand() % (5 - 2 + 1);
        string sy[x], med[x];
        int mrps[x], qty[x];
        Billing h;
        // random symptoms generation

        cout << "Pharmacy: Do you have a prescription??" << endl;
        cout << "Person: No sir! But I am suffering from ";
        for (int i = 0; i < x; i++)
        {
            h.gen_med(1 + rand() % (total - 1 + 1), sy, med, i, mrps);
            qty[i] = 3 + rand() % (10 - 3 + 1);
        }

        // printing symptoms
        for (int i = 0; i < x; i++)
        {
            cout << sy[i];
            if (i != x - 1)
                cout << ", ";
        }
        cout << ". Please help me with some medicine!!" << endl;

        // medicines by pharmacy
        cout << "Pharmacy: ";
        for (int i = 0; i < x; i++)
        {
            cout << med[i];
            Medicine u;
            u.updateStock(med[i], qty[i]);
            if (i != x - 1)
                cout << ", ";
        }
        cout << " might work for you." << endl;

        // generating bill
        amt = h.generate_bill(med, qty, x, mrps);
    }
    // save
    fstream save;
    save.open("saving.txt", ios::app | ios::out);
    save << cNo++ << " " << fullName << " " << d << " " << m << " " << y << " " << date << " " << amt << "\n";
    save.close();
}

void person::random()
{
    fstream file;
    firstName = arrfn[rand() % 26];
    lastName = arrln[rand() % 26];
    fullName = firstName + lastName;
    y = 2019 + rand() % 2;
    m = 1 + rand() % 12;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        d = 1 + rand() % 31;
    }
    else if (m == 2)
    {
        d = 1 + rand() % 27;
    }
    else
    {
        d = 1 + rand() % 30;
    }
    date = y * 10000 + m * 100 + d;
}

void person::printdata()
{
    cout << " -------------------------------------------------------------------------------------------------- \n";
    cout << "|                                                                                                  |\n";

    // cout << "\t\t\tFirst name :" << firstName;
    // cout << "\t\t\tLast name :" << lastName << endl;
    cout << "|\t\t\tFull name :" << setw(20) << fullName << "\t\t\t\t\t\t   |" << endl;
    cout << "|\t\t\tDate of order :" << setw(2) << d << "-" << setw(2) << m << "-" << y << "\t\t\t\t\t\t   |" << endl;
    cout << "|__________________________________________________________________________________________________|\n";
}
void person::transcount()
{
    fstream file;
    file.open("saving.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        int found = 0;
        string name = arrfn[rand() % 26] + arrln[rand() % 26];
        cout << "\t\t\tname: " << name;
        file >> cNo >> fullName >> d >> m >> y >> date >> amt;
        while (!file.eof())
        {
            if (name == fullName)
            {
                found++;
            }
            file >> cNo >> fullName >> d >> m >> y >> date >> amt;
        }
        cout << "\n\t\t\tTotal no. of transactions : " << found << endl;

        if (found == 0)
        {
            cout << "\t\t\tno data of person " << endl;
        }
        file.close();
    }
}

void person ::lasttrans()
{
    string name = arrfn[rand() % 26] + arrln[rand() % 26];
    int found = 0;
    // cout << "\t\t\tName : " << name << endl;
    fstream file;
    file.open("saving.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        cout << "\t\t\tName: " << name << endl;
        file >> cNo >> fullName >> d >> m >> y >> date >> amt;
        while (!file.eof())
        {
            if (name == fullName)
            {
                found++;
                cout << "\t\t\t" << found << " " << fullName << " " << d << "-" << m << "-" << y << " " << amt;
            }
            file >> cNo >> fullName >> d >> m >> y >> date >> amt;
        }
        cout << "\n\t\t\tTotal no. of transactions : " << found << endl;

        if (found == 0)
        {
            cout << "\t\t\tno data of person " << endl;
        }
        file.close();
    }
}
void person::last5()
{
    fstream file;
    int count = 0, h = 0;
    file.open("saving.txt", ios::in);
    file >> cNo >> fullName >> d >> m >> y >> date >> amt;

    while (!file.eof())
    {
        count++;
        file >> cNo >> fullName >> d >> m >> y >> date >> amt;
    }
    // cout<<count<<endl;
    file.close();

    file.open("saving.txt", ios::in);
    file >> cNo >> fullName >> d >> m >> y >> date >> amt;
    cout << "+------------------------------------------------------+" << endl;
    cout << "|" << setw(28) << "|" << setw(19) << "|" << setw(8) << "|" << endl;
    cout << "|" << setw(25) << "Name of the person"
         << "  |" << setw(19) << "Date   |" << setw(8) << "Amount|"
         << "\n";
    cout << "|" << setw(28) << "|" << setw(19) << "|" << setw(8) << "|" << endl;
    cout << "+------------------------------------------------------+" << endl;
    cout << "|" << setw(28) << "|" << setw(19) << "|" << setw(8) << "|" << endl;
    while (!file.eof())
    {
        h++;
        if (h > count - 5 && h <= count)
        {
            cout << "|" << setw(25) << fullName << "  |" << setw(7) << d << "-" << setw(2) << m << "-" << y << "   |" << setw(5) << amt << "  |"
                 << "\n";
            cout << "|" << setw(28) << "|" << setw(19) << "|" << setw(8) << "|" << endl;
        }
        file >> cNo >> fullName >> d >> m >> y >> date >> amt;
    }
    cout << "+------------------------------------------------------+" << endl;
    file.close();
}
void person::showTransactionData()
{
    fstream file;
    file.open("saving.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data Is Present...........";
    }
    else
    {
        file >> cNo >> fullName >> d >> m >> y >> date >> amt;
        cout << "+------------------------------------------------------+" << endl;
        cout << "|" << setw(28) << "|" << setw(19) << "|" << setw(8) << "|" << endl;
        cout << "|" << setw(25) << "Name of the person"
             << "  |" << setw(19) << "Date   |" << setw(8) << "Amount|"
             << "\n";
        cout << "|" << setw(28) << "|" << setw(19) << "|" << setw(8) << "|" << endl;
        cout << "+------------------------------------------------------+" << endl;
        cout << "|" << setw(28) << "|" << setw(19) << "|" << setw(8) << "|" << endl;
        while (!file.eof())
        {
            cout << "|" << setw(25) << fullName << "  |" << setw(7) << d << "-" << setw(2) << m << "-" << y << "   |" << setw(5) << amt << "  |"
                 << "\n";
            cout << "|" << setw(28) << "|" << setw(19) << "|" << setw(8) << "|" << endl;
            file >> cNo >> fullName >> d >> m >> y >> date >> amt;
        }
    }
    file.close();
    cout << "+------------------------------------------------------+" << endl;
}
void person::showTransactionBydate()
{
    fstream file;
    file.open("saving.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data Is Present...........";
    }
    else
    {
        int flag = 0;
        int dat = 20200817;
        file >> cNo >> fullName >> d >> m >> y >> date >> amt;
        cout << "+------------------------------------------------------+" << endl;
        cout << "|" << setw(28) << "|" << setw(19) << "|" << setw(8) << "|" << endl;
        cout << "|" << setw(25) << "Name of the person"
             << "  |" << setw(19) << "Date   |" << setw(8) << "Amount|"
             << "\n";
        cout << "|" << setw(28) << "|" << setw(19) << "|" << setw(8) << "|" << endl;
        cout << "+------------------------------------------------------+" << endl;
        cout << "|" << setw(28) << "|" << setw(19) << "|" << setw(8) << "|" << endl;
        while (!file.eof())
        {
            if (date == dat)
            {
                flag = 1;
                cout << "|" << setw(25) << fullName << "  |" << setw(7) << d << "-" << setw(2) << m << "-" << y << "   |" << setw(5) << amt << "  |"
                     << "\n";
                cout << "|" << setw(28) << "|" << setw(19) << "|" << setw(8) << "|" << endl;
            }
            file >> cNo >> fullName >> d >> m >> y >> date >> amt;
        }
        if (flag == 0)
        {
            cout << "\n\t\t\tNo transactions on that day\n";
        }
    }
    file.close();
    cout << "+------------------------------------------------------+" << endl;
}
/*----------------------------------------------------------------------------------------------- */
class admin : public person
{
public:
    //    admin();
    Medicine ma;

    void menu()
    {
        int option;
        Medicine ma;
        symptom SYMP;
    Start:
        cout << "\n================================================================================================" << endl;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t|        IIITs Pharmacy      |" << endl;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t 1. Creating data of Customer" << endl;
        cout << "\t\t\t 2. Medicine data" << endl;
        cout << "\t\t\t 3. Symptoms data " << endl;
        cout << "\t\t\t 4. Customer Transaction Details " << endl;
        cout << "\t\t\t 5. Customer Transaction Details On a particular date " << endl;
        cout << "\t\t\t 9. Back" << endl;
        cout << "\t\t\t 0. Exit" << endl;
        cout << "\t\t\t---------------------------" << endl;
        cout << "\t\t\tChoose Option:[1/2/3/9/0]" << endl;
        cout << "\t\t\t---------------------------" << endl;
        cout << "\n\t\t\tEnter Your Choose: ";
        cin >> option;
        cout << endl;
        cout << "\t\t\t---------------------------" << endl;
        switch (option)
        {

        case 1:
            // creating data
            Create();
            goto Start;
            break;

        case 2:
            // tablet data
            ma.showMedicinesData();
            goto Start;
            break;

        case 3:
            // Symptoms data
            SYMP.menus();
            goto Start;
            break;
        case 4:
            // customer transactions
            showTransactionData();
            goto Start;
            break;
        case 5:
            // show customer transactions according to date
            showTransactionBydate();
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
class receptionist : public person,public Medicine
{
public:
    //    receptionist();

    void menu()
    {
        int option;
    Start:
        cout << "\n================================================================================================" << endl;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t|        IIITs Pharmacy      |" << endl;
        cout << "\t\t\t-----------------------------" << endl;
        cout << "\t\t\t 1. Creating data of Customer" << endl;
        cout << "\t\t\t 2. Medicine data" << endl;
        cout << "\t\t\t 3. Last trasactions" << endl;
        cout << "\t\t\t 9. Back" << endl;
        cout << "\t\t\t 0. Exit" << endl;
        cout << "\t\t\t---------------------------" << endl;
        cout << "\t\t\tChoose Option:[1/2/3/9/0]" << endl;
        cout << "\t\t\t---------------------------" << endl;
        cout << "\n\t\t\tEnter Your Choose: ";
        cin >> option;
        cout << endl;
        cout << "\t\t\t---------------------------" << endl;
        switch (option)
        {

        case 1:
            // creating data
            Create();
            goto Start;
            break;

        case 2:
            showMedicinesData();
            // medicine data
            goto Start;
            break;

        case 3:
            last5();
            goto Start;
            break;
        case 9:
            // back
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
class customer : public person 
{
public:
    //    customer();
    void menu()
    {
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
        cout << "\n\t\t\tEnter Your Choose: ";
        cin >> option;
        cout << endl;
        cout << "\t\t\t---------------------------" << endl;
        switch (option)
        {

        case 1:
            // Total Transactions Made
            transcount();
            goto Start;
            break;

        case 2:
            // Latest Transaction
            lasttrans();
            goto Start;
            break;

        case 9:
            // back
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
    // radom generation
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
    cout << "\n\t\t\tEnter Your Choose: ";
    cin >> option;
    cout << endl;
    cout << "\t\t\t---------------------------" << endl;
    switch (option)
    {
    case 1:
        // admin login
        a.menu();
        break;

    case 2:
        // receptionist login
        r.menu();
        break;

    case 3:
        // customer login
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
