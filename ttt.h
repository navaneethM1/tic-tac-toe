//1,X-human
//2,O-comp

class Board
{
    int b[3][3];
    int number_of_moves;
    bool game_over();
    bool is_valid(int n);
    void comp_move();
    void draw();
public :
    Board();
    void move(int n);
};

void disp_instr();