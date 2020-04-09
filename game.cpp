#include <iostream>
#include <stdlib.h>
#include "ttt.h"
using namespace std;

int main()
{
    Board board;
    disp_instr();
    int x;
    while(1)
    {
        cin >> x;
        board.move(x);
    }
    return 0;
}