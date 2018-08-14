#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>

using namespace std;
int reconcile();
int main()
{
    int n;
    ("cls");
    cout<<"\n\n\n\t\t\t\t\t\tWelcome to Reconciliator"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\t1. Reconciliate Table Data"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\t2. Exit"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\t";
    cin>>n;
    switch(n)
    {
    case 1:
        reconcile();
    case 2:
        exit(0);
    }
    return 0;
}
int reconcile()
{
    int n1,n2,i,j;
    float vch1[4000],vch2[4000],val1[4000],val2[4000],val3[4000],diff[4000];
    //Data Entry for Table 1
    cout<<"Enter No. of entries in table 1"<<endl;
    cin>>n1;
    cout<<"Enter voucher Id's for table 1"<<endl;
    for(i=1;i<=n1;i++)
    {
        cin>>vch1[i];
    }
    cout<<"Enter amount for table 1"<<endl;
    for(i=1;i<=n1;i++)
    {
        cin>>val1[i];
    }

    //Data entry for table 2
    cout<<"Enter No. of entries in table 2"<<endl;
    cin>>n2;
    cout<<"Enter voucher Id's for table 2"<<endl;
    for(i=1;i<=n2;i++)
    {
        cin>>vch2[i];
    }
    cout<<"Enter amount for table 2"<<endl;
    for(i=1;i<=n2;i++)
    {
        cin>>val2[i];
    }

    //Computation of difference(Reconciliation)

    for(i=1;i<=n1;i++)
    {
        for(j=1;j<=n2;j++)
        {
            if(vch1[i]==vch2[j])
            {
                val3[i]=val2[j];
                diff[i]=val1[i]-val2[j];
            }
        }
    }


    //For ruling out garbage value in difference array
    for(i=1;i<=n1;i++)
    {
        if(val3[i]==0)
        {
            diff[i]=0;
        }
    }



    //Writing all of it in a Text file

   ofstream outfile;
   outfile.open("recon.txt");
   for(i=1;i<=n1;i++)
   {
       outfile<<vch1[i]<<"\t"<<val1[i]<<"\t"<<val3[i]<<"\t"<<diff[i]<<endl;
   }
   outfile.close();

   return 0;
}
