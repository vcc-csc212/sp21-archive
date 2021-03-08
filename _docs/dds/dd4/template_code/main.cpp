#include "tic-tac-toe.h"

int main(int argc, char** argv)
{
    bool ai_mode = false;

    if (argc == 2) {
        ai_mode = true;
    }

    ttt_game *game = new ttt_game(ai_mode);
    game->play();
    delete game;
}