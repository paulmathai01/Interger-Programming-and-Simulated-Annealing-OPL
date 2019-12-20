//
//  simulated_annealing.cpp
//  C++
//
//  Created by Paul Mathai on 16/12/19.
//  Copyright © 2019 Paul Mathai. All rights reserved.
//  Simulated Anealing

#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdlib>
#include<time.h>
using namespace std;
const int size = 100;
const int x = 100;
const int col = x+7;
const int row = x+1;
int main()
{
    cout<<"Simulated Annealing"<<endl;
    ifstream infile,infile2;
    ofstream outfile;
    float data[row+1][col+1];
    float a,g[size],h[size];
    infile.open("/Users/paulmathai/WSU/DSA6200/OPL Term Project/airland data/sol_airland100.txt");
    infile2.open("/Users/paulmathai/WSU/DSA6200/OPL Term Project/airland data/airland100.txt");
    float x[size],alpha[size],beta[size];
    for(int i = 1;i<size;i++)
    {
        infile>>a;
        x[i] = a;
        //cout<<x[i]<<" ";
    }
    cout<<endl;
    for(int i = 1;i<size;i++)
    {
        infile>>a;
        alpha[i] = a;
        cout<<alpha[i]<<" ";
    }
    cout<<endl;
    for(int i = 1;i<size;i++)
    {
        infile>>a;
        beta[i] = a;
        cout<<beta[i]<<" ";
    }
    for(int i = 1; i<row;i++)
    {   data[i][1] = i;
        for(int j = 2;j<col+1;j++)
        {
            infile>>a;
            data[i][j]=a;
        }
        g[i] = data[i][6];
        h[i] = data[i][7];
        cout<<g[i]<<" "<<h[i];
        
    }
    float minreturn = 0;
    for (int i =0; i<size;i++)
    {
        minreturn = minreturn + (g[i]*alpha[i]) + (h[i]*beta[i]);
    }
    cout<<"Current Z Value ="<<minreturn<<endl;
    
    for(int i =1; i<row;i++)
    {
        for(int j=1;j<col+1;j++)
        {
            srand(time(NULL));
            int val = rand() % 51;
            if(val%2 == 0)
            {
                beta[i] += val;
            }
            else
            {
                beta[i] -= val;
            }
        }
    }
    minreturn = 0;
    for (int i =0; i<size;i++)
    {
        minreturn = minreturn + (g[i]*alpha[i]) + (h[i]*beta[i]);
    }
    cout<<"Iteration 1 Z Value ="<<minreturn<<endl;
    for(int i =1; i<row;i++)
    {
        for(int j=1;j<col+1;j++)
        {
            srand(time(NULL));
            int val = rand() % 51;
            if(val%2 == 0)
            {
                beta[i] += val;
            }
            else
            {
                beta[i] -= val;
            }
        }
    }
    minreturn = 0;
    for (int i =0; i<size;i++)
    {
        minreturn = minreturn + (g[i]*alpha[i]) + (h[i]*beta[i]);
    }
    cout<<"Iteration 2 Z Value ="<<minreturn<<endl;
    for(int i =1; i<row;i++)
    {
        for(int j=1;j<col+1;j++)
        {
            srand(time(NULL));
            int val = rand() % 51;
            if(val%2 == 0)
            {
                beta[i] += val;
            }
            else
            {
                beta[i] -= val;
            }
        }
    }
    minreturn = 0;
    for (int i =0; i<size;i++)
    {
        minreturn = minreturn + (g[i]*alpha[i]) + (h[i]*beta[i]);
    }
    cout<<"Iteration 3 Z Value ="<<minreturn<<endl;
    for(int i =1; i<row;i++)
    {
        for(int j=1;j<col+1;j++)
        {
            srand(time(NULL));
            int val = rand() % 51;
            if(val%2 == 0)
            {
                beta[i] += val;
            }
            else
            {
                beta[i] -= val;
            }
        }
    }
    minreturn = 0;
    for (int i =0; i<size;i++)
    {
        minreturn = minreturn + (g[i]*alpha[i]) + (h[i]*beta[i]);
    }
    cout<<"Iteration 4 Z Value ="<<minreturn<<endl;
    for(int i =1; i<row;i++)
    {
        for(int j=1;j<col+1;j++)
        {
            srand(time(NULL));
            int val = rand() % 51;
            if(val%2 == 0)
            {
                beta[i] += val;
            }
            else
            {
                beta[i] -= val;
            }
        }
    }
    minreturn = 0;
    for (int i =0; i<size;i++)
    {
        minreturn = minreturn + (g[i]*alpha[i]) + (h[i]*beta[i]);
    }
    cout<<"Iteration 5 Z Value ="<<minreturn<<endl;
    for(int i =1; i<row;i++)
    {
        for(int j=1;j<col+1;j++)
        {
            srand(time(NULL));
            int val = rand() % 51;
            if(val%2 == 0)
            {
                beta[i] += val;
            }
            else
            {
                beta[i] -= val;
            }
        }
    }
    minreturn = 0;
    for (int i =0; i<size;i++)
    {
        minreturn = minreturn + (g[i]*alpha[i]) + (h[i]*beta[i]);
    }
    cout<<"Iteration 6 Z Value ="<<minreturn<<endl;
    for(int i =1; i<row;i++)
    {
        for(int j=1;j<col+1;j++)
        {
            srand(time(NULL));
            int val = rand() % 51;
            if(val%2 == 0)
            {
                beta[i] += val;
            }
            else
            {
                beta[i] -= val;
            }
        }
    }
    minreturn = 0;
    for (int i =0; i<size;i++)
    {
        minreturn = minreturn + (g[i]*alpha[i]) + (h[i]*beta[i]);
    }
    cout<<"Iteration 7 Z Value ="<<minreturn<<endl;
    for(int i =1; i<row;i++)
    {
        for(int j=1;j<col+1;j++)
        {
            srand(time(NULL));
            int val = rand() % 51;
            if(val%2 == 0)
            {
                beta[i] += val;
            }
            else
            {
                beta[i] -= val;
            }
        }
    }
    minreturn = 0;
    for (int i =0; i<size;i++)
    {
        minreturn = minreturn + (g[i]*alpha[i]) + (h[i]*beta[i]);
    }
    cout<<"Iteration 8 Z Value ="<<minreturn<<endl;
}

 
 

 
    
