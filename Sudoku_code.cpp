#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// displaying the sudoku 
void show(int (&array)[9][9])
{
    cout << endl<< endl;
    cout << "          ";
    for(int i=1;i<=9;i++) 
    {
        cout << i << "   ";
        if(i%3==0)
        {
            cout << "        ";
        }
    }
    cout << endl << endl;
    for(int i=0;i<9;i++)
    {
        cout << " " << (i+1) << "   ";
        cout << "   | ";
        for(int j=0;j<9;j++)
        {
            if(array[i][j] == 0)
            {
                cout << "  ";
            }
            else
            {
                cout << array[i][j] << " ";
            }
            // cout << array[i][j] << " ";
            cout << "| "; 
            if( j==2 || j==5)
            {
                cout << "      | ";
            }
        }
        cout << endl; 
        if( i==2 || i==5)
        {
            cout << endl<< endl;
        }
    }

    cout << endl << endl;
}

// insertion check 
bool check_for_generation(int (&array)[9][9] , int element , int row, int col)
{
    int i=row-1;
    int j=col-1;
    // posn check 
    if( array[i][j] != 0 )
    {
        return false;
    }
    // row check 
    for(int a=0;a<9;a++)
    {
        if(array[i][a] == element) return false;
    }
    // col check 
    for(int a=0;a<9;a++)
    {
        if(array[a][j] == element) return false;
    }

    int test = i/3;
    int startrow = 3*test;
    int endrow = startrow + 2;

    int test1 = j/3;
    int startcol = 3*test1;
    int endcol = startcol + 2;

    // mini matrix check 
    for(int x= startrow;x<=endrow;x++)
    {
        for(int y=startcol;y<=endcol;y++)
        {
            if(array[x][y] == element)
            {
                return false;
            }
        }
    }
    return true;
}

// initialising the value 
void generateSudoku(int (&array)[9][9])
{
    int x =time(0);
    srand(x);
    int count = 50;
    while(count > 0)
    {
        // cout << "hi";
        int row= 1 + rand() % 10;
        int col= 1 + rand() % 10;
        int num= 1 + rand() % 9;
        
        bool test =  check_for_generation(array, num, row, col);
        if(test == true)
        {
            array[row-1][col-1] = num;
            count--;
        }
            count--;
    }
    // cout << "Shrajan";
    show(array);
}

//checking if the game is over ?
bool checkover(int (&array)[9][9])
{
    for(int i=0;i<9;i++)
    {
      for(int j=0;j<9;j++)  
      {
        if(array[i][j] == 0)
        {
            return false;
        }
      }
    }
}

bool check_for_game(int (&array)[9][9],int element,int row, int col)
{
    if( element < 0 || element > 10)
    {
        cout << " Game over bcz element out of range" << endl;
        return false;
    }

    int i=row-1;
    int j=col-1;

    if( i<0 || i >8)
    {
        cout << " Game over bcz row out of range" << endl;
        return false;
    }

    if( j<0 || j >8)
    {
        cout << " Game over bcz col out of range" << endl;
        return false;
    }
    
    if( array[i][j] != 0 )
    {
        cout << " Game over bcz posn already filled" << endl;
        return false;
    }

    // row check 
    for(int a=0;a<9;a++)
    {
        if(array[i][a] == element)
        {
            cout << " Game over bcz element already exists in row" << endl;
            return false;
        }
    }
    // col check 
    for(int a=0;a<9;a++)
    {
        if(array[a][j] == element)
        {
            cout << " Game over bcz element already exists in col" << endl;
            return false;
        }
    }

    int test = i/3;
    int startrow = 3*test;
    int endrow = startrow + 2;

    int test1 = j/3;
    int startcol = 3*test1;
    int endcol = startcol + 2;

    // mini matrix check 
    for(int x= startrow;x<=endrow;x++)
    {
        for(int y=startcol;y<=endcol;y++)
        {
            if(array[x][y] == element)
            {
                return false;
            }
        }
    }
    return true;
}

//startiing the game function
void startgame(int (&array)[9][9])
{
    cout << endl;
    cout << "To start game enter following values:- ";

    bool checking =true;

    while(checking)
    {
        int row;
        int col;
        int value;
        cout << " Enter the row : "; cin >> row; cout << endl;
        cout << " Enter the column : "; cin >> col; cout << endl;
        cout << " Enter the value(0-9) : "; cin >> value; cout << endl;
        checking = check_for_game(array,value,row,col);

        bool test =  check_for_generation(array,value,row,col);
        if(test)
        {
            array[row-1][col-1] = value;
        }
        show(array);
        if(!checking)
        {
           cout << endl << "Game Over" << endl; 
        }

        if(checkover(array))
        {
            cout << endl << "Game Over.....You won !!!" << endl;
        }
    }
}

// main function 
int main()
{
    cout << endl;
    cout << " ***** Hello Player, welcome to Sudoku ***** "<< endl;
    int arr[9][9] = {0};

    // generate a new sudoku problem
    generateSudoku(arr);
    startgame(arr);

    return 0;
}

