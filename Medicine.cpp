#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <iomanip>
using namespace std;
static int id = 35;
class Date
{
public:
    int yy, mm, dd;
    int generateDate();
};
int Date ::generateDate()
{
    yy = 2010 + rand() % (2020 - 2010 + 1);
    mm = 1 + rand() % 12;
    if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
        dd = 1 + rand() % 31;
    else if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
        dd = 1 + rand() % 30;
    else if (yy % 4 == 0 && mm == 2)
        dd = 1 + rand() % 28;
    else
        dd = 1 + rand() % 27;
    int date = yy * 10000 + mm * 100 + dd;
    return date;
}
static int total = 35;
class Medicine
{
private:
    int mid;
    char name[20];
    int mfg;
    int exp;
    char symptom[30];
    int no_of_tablets;

public:
    float mrp;
    void AddMedicineDetails();
    void showMedicinesData();
    void searchMedicine(char *s);
};

void Medicine ::AddMedicineDetails()
{
    fstream file;
    mid = id++;
    cout << "Enter name of medicine :" << endl;
    cin >> name;
    mrp = 20 + rand() % 50;
    Date d1, d2;
    mfg = d1.generateDate();
    exp = d2.generateDate();
    int temp1 = mfg / 10000;
    int temp2 = exp / 10000;
    if (temp1 > temp2)
    {
        temp2 = exp % 10000;
        exp = exp / 10000 + 1;
        exp = exp * 10000 + temp2;
    }
    cout << "What is it used for :" << endl;
    cin >> symptom;
    no_of_tablets = 1000 + rand() % (2000 - 1000 + 1);
    file.open("medicines.txt", ios::app | ios::out);
    file << mid << "    " << name << "   " << mrp << "  " << mfg << "   " << exp << "   " << symptom << "   " << no_of_tablets << "\n";
    file.close();
    cout << "Medicine successfully added !!!" << endl;
}

void Medicine::showMedicinesData()
{
    fstream file;
    file.open("medicines.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data Is Present...........";
    }
    else
    {
        file >> mid >> name >> mrp >> mfg >> exp >> symptom >> no_of_tablets;
        cout << "\t\t\t-----------------------------------------------------------";
        while (!file.eof())
        {
            cout.setf(ios::adjustfield);
            cout << "\n"
                 << "\t\t\t|" << setw(3) << mid;
            cout << "|" << setw(25) << name;
            cout << "|" << setw(5) << mrp;
            cout << "|" << setw(10) << mfg;
            cout << "|" << setw(10) << exp << "|";
            file >> mid >> name >> mrp >> mfg >> exp >> symptom >> no_of_tablets;
        }
    }
    file.close();
    cout << "\n\t\t\t-----------------------------------------------------------" << endl;
}

void Medicine ::searchMedicine(char *s)
{
    ifstream file;
    file.open("medicines.txt", ios::in | ios ::binary);
    if (!file)
    {
        cout << "\n\t\tNo Data found .........."
             << "\n";
    }
    else
    {
        // file.read();
        file >> mid >> name >> mrp >> mfg >> exp >> symptom >> no_of_tablets;
        if (strcmp(s, symptom))
        {
            cout.setf(ios::right);
            cout << "\n"
                 << setw(25) << mid;
            cout << "|" << setw(25) << name;
            cout << "|" << setw(25) << mrp;
            cout << "|" << setw(25) << mfg;
            cout << "|" << setw(25) << exp;
        }
    }
    file.close();
}
