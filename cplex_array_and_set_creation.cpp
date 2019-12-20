//
//  cplex_array_and_set_creation.cpp
//  C++
//
//  Created by Paul Mathai on 16/12/19.
//  Copyright © 2019 Paul Mathai. All rights reserved.
//  Converting the structured data into array format for CPLEX

#include<iostream>
#include<fstream>
using namespace std;
const int x = 100;
const int col = x+7;
const int row = x+1;
void output(float data[row+1][col+1], int ind)
{
    cout<<"\nnext\n";
    cout<<"\n[";
    for(int i = 1;i<row;i++)
    {
        cout<<data[i][ind];
        if(i != row-1)
        {
            cout<<",";
        }
    }
    cout<<"]\n";
}
int main()
{
    float data[row+1][col+1];
    ifstream infile;
    ofstream outfile;
    float a;
    
    infile.open("/Users/paulmathai/WSU/DSA6200/OPL Term Project/airland data/airland100.txt");
    for(int i = 1; i<row;i++)
    {   data[i][1] = i;
        for(int j = 2;j<col+1;j++)
        {
            infile>>a;
            data[i][j]=a;
        }
        
    }
    //checking for data integrity
    /*
    for(int i = 1; i<row;i++)
    {
        for(int j = 1;j<col+1;j++)
        {
            cout<<data[i][j]<<" ";
        }
        cout<<"\n";
    }
    */
    //outputing in CPLEX format for initial variables
    for(int i = 1;i<8;i++)
    {
        output(data,i);
    }
    cout<<"\nnext\n";
    cout<<"\n";
    //outputing the s matrix in CPLEX format
    cout<<"[";
    for(int i = 1; i<row;i++)
    {
        cout<<"[";
        for(int j = 8;j<col+1;j++)
        {
            cout<<data[i][j];
            if(j != col)
            {
                cout<<",";
            }
        }
        cout<<"]";
    }
    cout<<"]\n";
    //Creating set for U union W
    int uw[row+1][col-6] ={0};
    for(int i = 1; i<row-1;i++)
    {
        for(int j = 2;j<col+1;j++)
        {
            if((data[i][7]<data[j][5] && (data[i][7] + data[i][j] <= data[j][5])) && (((data[j][5]<= data[i][5] && data[i][5] <= data[j][7]) || (data[j][5] <= data[i][7] && data[i][7] < data[j][7]) || ((data[i][5] <= data[j][5]) && data[j][5] <= data[i][7]) || ((data[i][5]<= data[j][7]) && ( data[j][7] <= data[i][7]))) && (i!= j)))
            {
                //x[i][j] = 1;
                uw[i][j] = 1;
                
            }
        }
    }
    //Cretaing set for V
    int v[row+1][col-6] ={0};
    for(int i =1; i<row;i++)
    {
        for(int j = 2;j<col+1;j++)
        {
            if((data[i][7]<data[j][5] && (data[i][7] + data[i][j] > data[j][5])))
            {
                //x[i][j] = 1;
                v[i][j] = 1;

            }
        }
    }
    cout<<"\nnext\n";
    //Outputing the set u union w
    cout<<"\n[";
    for( int i = 1;i <row; i++)
    {
        cout<<"[";
        for( int j =1 ;j<col-6;j++)
        {
            cout<<uw[i][j];
            if( j != col-7)
            {
                cout<<",";
            }
        }
        cout<<"]";
        
    }
    cout<<"\nnext\n";
    cout<<"]\n";
    //Outputing the set v
    cout<<"\n[";
    for( int i = 1;i <row; i++)
    {
        cout<<"[";
        for( int j =1 ;j<col-6;j++)
        {
            cout<<v[i][j];
            if( j != col-7)
            {
                cout<<",";
            }
        }
        cout<<"]";
        
    }
    cout<<"]\n";
}
