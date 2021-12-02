#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <iomanip>
#include "oops.cpp"
using namespace std;
class Medicine : public symptom
{
private:
    long long int id;
    char name[20];
    char mfg[15];
    char exp[15];
    char symptom[30];
    int no_of_sheets;

public:
    float mrp;
    void AddMedicineData();
    void showMedicinesData();
    void searchMedicine(char *s);
};

void Medicine::AddMedicineData()
{
    fstream file;
    cout << "\n------------------------------------------------------------------------------------------------";
    cout << "\n---------------------------------- Add Medicine Details -----------------------------------------" << endl;

    cout << "Enter name of medicine :" << endl;
    cin >> name;
    cout << "Enter mrp :" << endl;
    cin >> mrp;
    cout << "Enter maufaturing date :" << endl;
    cin >> mfg;
    cout << "Enter expiry date :" << endl;
    cin >> exp;
    cout << "What is it used for :" << endl;
    cin >> symptom;
    cout << "No of sheets :" << endl;
    cin >> no_of_sheets;
    file.open("medicines.txt", ios::app | ios::out);
    file << name << " " << mrp << " " << mfg << " " << exp << " " << symptom << " " << no_of_sheets << "\n";
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
        file.close();
    }
    else
    {
        file >> id >> name >> mrp >> mfg >> exp;
        while (!file.eof())
        {
            cout.setf(ios::right);
            cout << "\n"
                 << setw(15) << id;
            cout << "|" << setw(15) << name;
            cout << "|" << setw(15) << mrp;
            cout << "|" << setw(15) << mfg;
            cout << "|" << setw(15) << exp;
        }
    }
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
        file >> id >> name >> mrp >> mfg >> exp >> symptom;
        if (s == symptom)
        {
            cout.setf(ios::right);
            cout << "\n"
                 << setw(15) << id;
            cout << "|" << setw(15) << name;
            cout << "|" << setw(15) << mrp;
            cout << "|" << setw(15) << mfg;
            cout << "|" << setw(15) << exp;
        }
    }
}
