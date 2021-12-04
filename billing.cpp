#include <iostream>
// #include<unistd.h>
#include<fstream>
#include<iomanip>
using namespace std;

static int n=3468;

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

class Medicine:public symptom
{
private:
    string medicine;
    int mrp;

public:
    void gen_med(int l, string sy[], string med[], int i,int mrps[]);
    void generate_bill(string med[],int qty[],int x,int mrps[]);
};

void Medicine::gen_med(int l,string sy[],string med[],int i,int mrps[]){
    fstream file1;
    //int no;
        file1.open("symp_med_mrp.txt", ios::in);
        //no=i;
        file1 >> sNo >> symp >> medicine >> mrp;

        while (!file1.eof())
        {
            if (sNo == l)
            {
                sy[i]=symp;
                med[i]=medicine;
                mrps[i]=mrp;
            }
            file1 >> sNo >> symp >> medicine >> mrp;
        }
        
        file1.close();

    }

void Medicine :: generate_bill(string med[],int qty[],int x,int mrps[]){
    float tot[x],rate[x],total=0;
    //cout<<"__________________________________________________________________________________________________"<<endl;//98
    //cout<<"*************************************#Generating Bill#********************************************"<<endl;
    //cout<<"__________________________________________________________________________________________________\n\n";
    cout<<" __________________________________________________________________________________________________"<<endl;
    cout<<"|"<<setw(99)<<"|"<<endl;
    cout<<"|                                          IIITS PHARMACY                                          |"<<endl;//99
    cout<<"|                             near XXX Bank,main road,Sricity,Chittoor                             |"<<endl;
    cout<<"|                      Contact Info:9347246185,8436542840;state: Andhra Pradesh                    |"<<endl;
    cout<<"|"<<setw(92)<<"BillNo:JH000/"<<n<<"/ |"<<endl;
    //date
    cout<<"|                                        GST INVOICE                                               |"<<endl;
    cout<<"|__________________________________________________________________________________________________|\n";
    cout<<"|"<<setw(25)<<" |"<<setw(13)<<" |"<<setw(13)<<" |"<<setw(16)<<" |"<<setw(16)<<" |"<<setw(16)<<" |"<<endl;
    cout<<"|"<<setw(25)<<"Product Name |"<<setw(13)<<"Qty   |"<<setw(13)<<"MRP   |"<<setw(16)<<"Rate  |"<<setw(16)<<"GST  |"<<setw(16)<<"Total   |"<<endl;
    cout<<"|________________________|____________|____________|_______________|_______________|_______________|\n";
    for(int i=0;i<x;i++){
        rate[i]=(mrps[i]/10)*qty[i];
        tot[i]=rate[i]+(18*rate[i])/100; // 18 percent gst
        total+=tot[i];
        cout<<"|"<<setw(25)<<" |"<<setw(13)<<" |"<<setw(13)<<" |"<<setw(16)<<" |"<<setw(16)<<" |"<<setw(16)<<" |"<<endl;
        cout<<"|"<<setw(23)<<med[i]<<" |"<<setw(11)<<qty[i]<<" |"<<setw(11)<<mrps[i]<<" |"<<setw(14)<<rate[i]<<" |"<<setw(14)<<(18*rate[i])/100<<" |"<<setw(14)<<tot[i]<<" |"<<endl;
        //cout<<"|"<<setw(25)<<" |"<<setw(13)<<" |"<<setw(13)<<" |"<<setw(16)<<" |"<<setw(16)<<" |"<<setw(16)<<" |"<<endl;
    }
    cout<<"|________________________|____________|____________|_______________|_______________|_______________|\n";
    cout<<"|"<<setw(99)<<"|"<<endl;
    cout<<"|"<<setw(90)<<"Total amount: Rs."<<total<<"  |"<<endl;
    cout<<"|__________________________________________________________________________________________________|\n";
}    
    
int main()
{
    srand((unsigned int)getpid());
    int k=0;  //k=0 => no prescrption; k=1 => have prescription
    int x=3+rand()%(5-2+1);
    string sy[x],med[x];
    int mrps[x],qty[x];
    Medicine h;
    switch(k){
        case 0:{
            //random symptoms generation
            cout<<"Pharmacy: Do you have a prescription??"<<endl;
            cout<<"Person: No sir! But I am suffering from ";
            for(int i=0;i<x;i++){
                h.gen_med(1+rand()%(37-1+1),sy,med,i,mrps);
                qty[i]=3+rand()%(10-3+1);
            }
            //printing symptoms
    
            for(int i=0;i<x;i++){
                cout<<sy[i];
                if(i!= x-1)cout<<", ";
            }
            cout<<". Please help me with some medicine!!"<<endl;

            //medicines by pharmacy
            cout<<"Pharmacy: ";
            for(int i=0;i<x;i++){
                cout<<med[i];
                if(i!= x-1)cout<<", ";
            }
            cout<<" might work for you."<<endl;

            //generating bill
            h.generate_bill(med,qty,x,mrps);

            break;
        }
        case 1:{
            break;
        } 
    }
    return 0;
}