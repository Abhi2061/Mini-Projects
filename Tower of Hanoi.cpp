
/* 
 * File:   tower_of_hanoi.cpp
 * Author: Abhishek Kumar
 *
 * Created on 6 October, 2020, 8:53 AM
 */

#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

vector<int> first, middle, last;

void display()
{
    cout<<endl;
    cout<<"Step "<<cnt++<<"\t";
    
    for(auto i=first.begin(); i!=first.end(); i++)
        cout<<*i<<" ";
    
    cout<<"\t";
    
    for(auto i=middle.begin(); i!=middle.end(); i++)
        cout<<*i<<" ";
    
    cout<<"\t";
    
    for(auto i=last.begin(); i!=last.end(); i++)
        cout<<*i<<" ";
}

void hanoi(vector<int> &f, vector<int> &m, vector<int> &l, int N)
{    
    if(N == 1)
    {
        l.push_back(f.back());
        f.pop_back();
        
        display();
    }
    else
    {
        hanoi(f, l, m, N-1);
        
        hanoi(f, m, l, 1);
        
        hanoi(m, f, l, N-1);
    }
    
}

int main(int argc, char** argv) {
    
    int N, i;
    
    cout<<"Enter the number of discs : ";
    cin>>N;
    
    i = N;
    
    while(i)
    first.push_back(i--);
    
    cout<<"Step\tFirst\tSecond\tThird\n";
    
    display();
    
    hanoi(first, middle, last, N);
   
    return 0;
}

