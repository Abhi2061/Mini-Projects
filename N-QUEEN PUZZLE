#include <bits/stdc++.h>

using namespace std;

// TO MARK THE CELLS THAT CANNOT BE  FILLED
void mark(vector<vector<int>> &B, int r, int c, int N)
{
    for(int i=0; i<N; i++)
    {
        B[i][c] = -1;
        B[r][i] = -1;
    }
    
    int j = 1;
 
    for(int i=r+1; i<N; i++)
    {
        if(c+j < N)
            B[i][c+j] = -1;
        if(c-j > -1)
            B[i][c-j] = -1;
        j++;
    }
    
    j = 1;
    
    for(int i=r-1; i>= 0; i--)
    {
        if(c+j < N)
            B[i][c+j] = -1;
        if(c-j > -1)
            B[i][c-j] = -1;
        j++;
    }
}

//A RECURSIVE FUNCTION WHICH RETURN TRUE WHEN ALL THE ALL QUEENS GET PLACED
bool N_queen(vector<vector<int>> &B, int r, int N)
{
    for(int i=0; i<N; i++)
    {
        if(B[r][i] != -1)
        {
            if(r < N-1)
            {
                vector<vector<int>> temp = B;
                mark(temp, r, i, N);
                temp[r][i] = r+1;
                if(N_queen(temp, r+1, N))
                {
                    B = temp;
                    return true;
                }
            }
            else
            {
                B[r][i] = r+1;
                return true;
            }
        }
    }
    
    return false;
}


int main(int argc, char** argv) {
    
    cout<<"Enter the Numbers of row : ";
    int N;
    cin>>N;
    cout<<endl;
    
    vector<vector<int>> A(N, vector<int>(N, 0));
    
    N_queen(A, 0, N);
    
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(A[i][j] < 1)
                cout<<"_ ";
            else
                cout<<A[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

