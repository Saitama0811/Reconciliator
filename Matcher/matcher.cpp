#include <iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>

using namespace std;

int main()
{
    int n, k = 0, voucher1[10000], voucher2[10000];
    float amt1[10000], amt2[10000];


    cout<<"Enter the number of rows";
    cin>>n;

    cout<<"Enter Voucher Numbers\n";
    for(int i = 0; i < n; i++) {
        cin>>voucher1[i];
    }

    cout<<"Enter the amount\n";
    for(int i = 0; i < n; i++) {
        cin>>amt1[i];
    }

    for(int i = 0; i < n; i++)
    {
        if(voucher1[i] != 0)
        {
            for(int j = i+1; j < n; j++)
            {
                if(voucher1[i] == voucher1[j])
                {
                    amt1[i] = amt1[i] + amt1[j];
                    voucher1[j] = 0;
                    amt1[j] = 0;
                }
            }
            voucher2[k] = voucher1[i];
            amt2[k] = amt1[i];
        }
        ++k;
    }

    for(int i = 0; i < k; i++) {
        cout<<voucher2[i]<<"\t"<<amt2[i]<<endl;
    }

    ofstream outfile;
    outfile.open("recon.txt");
    for(int i=0;i<k;i++)
    {
        outfile<<voucher2[i]<<"\t"<<amt2[i]<<endl;
    }
    outfile.close();

    return 0;
}
