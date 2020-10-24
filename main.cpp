/* 
    This program is a Sudoku Puzzle Solver
    It uses recursion and backtracking to solve the puzzle
 */


#include <bits/stdc++.h>
using namespace std;

//check whether the given value is possible to fill
bool check(int v, int r, int c, vector<vector<int>> B)
{   
    //Check the values in the given row as well as column
    for(int i=0; i<9; i++)
    {
        if(B[i][c] == v || B[r][i] == v)
            return false;
    }
    
    //Ckeck the values in the given sub box
    for(int i=(r/3)*3; i<((r/3)*3)+3; i++)
    {
        for(int j=(c/3)*3; j<((c/3)*3)+3; j++)
        {
            if(B[i][j] == v)
                return false;
        }
    }
    
    return true;
}

//A recursive function to solve the puzzle
bool solve(vector<vector<int>> &B)
{
    bool f = true;
    int i, j;
    
    //To find the first blank field
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(B[i][j] == 0)
            {
                f = false;
                break;
            }
        }
        if(!f)
            break;            
    }
    
    if(f)
        return true;
    
    //Try all values from 1 to 9 for the blank field
    for(int k=1; k<=9; k++)
    {
        if(check(k, i, j, B))
        {            
            vector<vector<int>> temp = B;
            temp[i][j] = k;
            if(solve(temp))
            {
                B = temp;
                return true;
            }
        }
    }
    
    return false;    
}
int main() {
    
    bool f = true;
    int c = 0, prev = -1;
    vector<vector<int>> B(9, vector<int>(9));
    
    //Input the initial values
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            cin>>B[i][j];
    }
    
    //Fill the values which can be filled without assumption
    while(c != prev)
    {
        prev = c;
        c = 0;
        f = false;
        
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                int temp, cnt = 0;
                if(B[i][j] == 0)
                {
                    
                    for(int k=1; k<10; k++)
                    {
                        if(check(k, i, j, B))
                        {
                            temp = k;
                            cnt++;
                        }

                        if(cnt > 1)
                            break;
                    }
                    if(cnt == 1)
                        B[i][j] = temp;
                    else
                    {
                        f = true;
                        c++;
                    }
                }
            }
        }
    }
    
    //Calling the solve function to fill values using backtracking
    solve(B);
    
    cout<<endl;
    
    //Print the solved puzzle
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            cout<<B[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

