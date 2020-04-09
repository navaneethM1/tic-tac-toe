#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "ttt.h"
using namespace std;

void disp_instr()
{
    cout << "\ttic tac toe" << endl << endl;
    cout << "Choose a cell numbered from 1 to 9 as below and play" << endl << endl << endl;
    int c = 1;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == 2)
            {
                cout << " " << c << " ";
            }
            else
            {
                cout << " " << c << " |";
            }
            c++;
        }
        cout << endl;
        if(i == 0 || i == 1)
        {
            cout << "-----------";
            cout << endl;
        }
    }
    cout << endl << endl << "- - - - - -" << endl << endl;
}

Board::Board() : number_of_moves(0)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            b[i][j] = -1;
        }
    }
}

void Board::move(int n)
{
    if(number_of_moves == 9)
    {
        cout << "Draw!" << endl;
        exit(1);
    }
    while(!is_valid(n))
    {
        cin >> n;
    }
    int i = (n-1)/3;
    int j = n%3?(n%3)-1:2;
    b[i][j] = 1;
    number_of_moves++;
    if(game_over())
    {
        cout << "Human has put a X in cell " << n << endl << endl;
        draw();
        cout << "Human wins!" << endl;
        exit(1);
    }
    cout << "Human has put a X in cell " << n << endl << endl;
    draw();
    comp_move();
    draw();
}

void Board::draw()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(b[i][j] == -1)
            {
                if(j == 2)
                {
                    cout << "   ";
                }
                else
                {
                    cout << "   |";
                }
            }
            else if(b[i][j] == 1)
            {
                if(j == 2)
                {
                    cout << " X ";
                }
                else
                {
                    cout << " X |";
                }
            }
            else if(b[i][j] == 2)
            {
                if(j == 2)
                {
                    cout << " O ";
                }
                else
                {
                    cout << " O |";
                }
            }
        }
        cout << endl;
        if(i == 0 || i == 1)
        {
            cout << "-----------";
            cout << endl;
        }
    }
    cout << endl << endl;
}

bool Board::is_valid(int n)
{
    if(n < 1 || n > 9)
        return false;
    int i = (n-1)/3;
    int j = n%3?(n%3)-1:2;
    if(b[i][j] == -1)
        return true;
    return false;
}

void Board::comp_move()
{
    if(number_of_moves == 9)
    {
        cout << "Draw!" << endl;
        exit(1);
    }
    int n = rand()%9 + 1;
    while(!is_valid(n))
    {
        n = rand()%9 + 1;
    }
    cout << "Computer has put a O in cell " << n << endl << endl;
    int i = (n-1)/3;
    int j = n%3?(n%3)-1:2;
    b[i][j] = 2;
    number_of_moves++;
    if(game_over())
    {
        cout << "Computer has put a O in cell " << n << endl << endl;
        draw();
        cout << "Computer wins!" << endl;
        exit(1);
    }
}

bool Board::game_over()
{
    //row checking
    int h,c;
    for(int i = 0; i < 3; i++)
    {
        h = 0; c = 0;
        for(int j = 0; j < 3; j++)
        {
            if(b[i][j] == 1)
                h++;
            else if(b[i][j] == 2)
                c++;
        }
        if(h == 3 || c == 3)
            return true;
    }
    //cols checking
    for(int i = 0; i < 3; i++)
    {
        h = 0; c = 0;
        for(int j = 0; j < 3; j++)
        {
            if(b[j][i] == 1)
                h++;
            else if(b[j][i] == 2)
                c++;
        }
        if(h == 3 || c == 3)
            return true;
    }
    //main diag check
    h = 0; c = 0;
    for(int i = 0; i < 3; i++)
    {
        if(b[i][i] == 1)
            h++;
        else if(b[i][i] == 2)
            c++;
    }
    if(h == 3 || c == 3)
        return true;
    //other diag check
    h = 0; c = 0;
    for(int i = 0; i < 3; i++)
    {
        if(b[2-i][i] == 1)
            h++;
        else if(b[2-i][i] == 2)
            c++;
    }
    if(h == 3 || c == 3)
        return true;
    return false;
}
