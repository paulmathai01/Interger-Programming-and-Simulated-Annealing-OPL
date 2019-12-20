//
//  txt_to_sturct_csv.cpp
//  C++
//
//  Created by Paul Mathai on 16/12/19.
//  Copyright © 2019 Paul Mathai. All rights reserved.
//  Converting the RAW text file into structured data and converting

#include<iostream>
#include<fstream>
using namespace std;

int main()
{   const int x = 500;
    const int col = x+7;
    const int row = x+1;
    ifstream infile;
    ofstream outfile;
    string a;
    
    infile.open("/Users/paulmathai/WSU/DSA6200/OPL Term Project/airland data/airland500.txt");
    outfile.open("/Users/paulmathai/WSU/DSA6200/OPL Term Project/airland data/new_airland500.txt");
    outfile<<"i,appt,e,t,l,g,h";
    for(int i = 1; i < row; i++)
    {
        outfile<<",s"<<i;
    }
    outfile<<"\n";
    for(int i = 1; i<row;i++)
    {   outfile<<i<<",";
        for(int j = 1;j<col;j++)
        {
            infile>>a;
            outfile<<a;
            if(j!=(col-1))
            {
                outfile<<",";
            }
        }
        outfile<<"\b\n";
        
    }
    infile.close();
    outfile.close();
    
    
    
}
