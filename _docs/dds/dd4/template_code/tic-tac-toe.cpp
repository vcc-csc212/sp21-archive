#include "tic-tac-toe.h"

#define BOARD_SIZE 9
#define ONGOING -1
#define OVER_TIE 0
#define OVER_WIN 1
#define P1_SYMBOL 'X'
#define P2_SYMBOL 'O'
#define PLAYER_1 0
#define PLAYER_2 1
#define MAX_VAL 1
#define TIE_VAL 0
#define MIN_VAL -1
#define MAX_DEPTH 5

ttt_game::ttt_game() {
    //TODO
}

ttt_game::ttt_game(bool ai_mode) {
    //TODO
}

ttt_game::~ttt_game() {
    //TODO
}

int ttt_game::game_status(char* board) {
    //TODO
    //HINT: USE THE MACROS GIVEN:
        //OVER_WIN if either player won
        //OVER_TIE if board is full and no player won
        //ONGOING if board still has open spots
}

std::string ttt_game::draw_board(char* board) {
    std::string partial_divider = "     |     |     \n";
    std::string full_divider = "_____|_____|_____\n" + partial_divider;
    std::string bar_divider = "  |  ";
    std::string front_space = "  ";
    
    std::string str("\n");
    str += partial_divider;
    str += front_space + board[0] + bar_divider + board[1] + bar_divider + board[2] + "\n";
    str += full_divider;
    str += front_space + board[3] + bar_divider + board[4] + bar_divider + board[5] + "\n";
    str += full_divider;
    str += front_space + board[6] + bar_divider + board[7] + bar_divider + board[8] + "\n";
    str += partial_divider + "\n";

    return str;
}

bool ttt_game::make_move(int location) {
    //TODO
    //HINT: USE THE MACROS GIVEN:
        //PLAYER_1 for representing player 1
        //PLAYER_2 for representing player 2
        //P1_SYMBOL for player 1's symbol which is X
        //P2_SYMBOL for player 2's symbol which is O
}

int ttt_game::minimax_algo(game_state* status, int depth) {
    //TODO
    //HINT: USE THE MACROS GIVEN:
        //OVER_WIN if either player won
        //MAX_VAL value returned if p1 (max) wins
        //MIN_VAL value returned if p2 (min) wins
        //OVER_TIE if board is full and no player won
        //TIE_VAL value returned if nobody wins
        //ONGOING if board still has open spots
        //PLAYER_1 for representing player 1
        //PLAYER_2 for representing player 2
        //P1_SYMBOL for player 1's symbol which is X
        //P2_SYMBOL for player 2's symbol which is O
        //MAX_DEPTH for the depth of the tree
}

int ttt_game::minimax_move() {
    int move = -1; 

    for (int i = 0; i < BOARD_SIZE && move == -1; i++) {
        if (_board[i] != P1_SYMBOL && _board[i] != P2_SYMBOL) {
            move = i;
        }
    }

    //assume current best is losing, ai is p2 is min so losing is max
    int best = MAX_VAL;

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (_board[i] != P1_SYMBOL && _board[i] != P2_SYMBOL) {
            _board[i] = P2_SYMBOL;
        

            game_state status = {
                _board, //_gs_board
                _current_player, //_gs_player
            };

            int val = minimax_algo(&status, 0);

            if (val < best) { //P2 is min
                move = i; 
            }

            _board[i] = i + '1';
        }
    }
    return move;
}

void ttt_game::play() {
    using std::cout;
    using std::endl;

    int status = ONGOING;
    std::string p2;
    char choice;
    int valid;

    if (_ai_mode) {
        p2 = "AI";
    } else {
        p2 = "Player 2";
    }

    cout << "\nWELCOME! Player 1 = X, " << p2 << " = O\n" << endl;

    while(status == ONGOING) {
        cout << draw_board(_board);

        if (_current_player == PLAYER_1 || _ai_mode == false) { 
            cout << "Player " << _current_player+1 << " make your move: ";
        
            do {
                std::cin.get(choice); //assumes only 1 char is being input, not good practice but alas, don't feel lke doing input validation, you're welcome to fix it if you'd like!
                std::cin.ignore(); //ignore enter line for next round
                valid = make_move(choice-49); //48 for ASCII, 1 more for offset of 0-indexed array
                if (!valid) {
                    cout << "\nInvalid move! Try again: ";
                }
            } while (!valid);
        } else {
            int ai_move = minimax_move();
            valid = make_move(ai_move);
            if (!valid) {
                cout << "\nINVALID AI MOVE TO POSITION " << ai_move+1 << ", minimax_move() HAS A BUG." << endl;
                break;
            }
            cout << "AI's move: " << ai_move+1 << endl;
        }        
        status = game_status(_board);
        _current_player = !_current_player;
    }

    cout << draw_board(_board);

    if (status == OVER_WIN) {
        cout << "Player " << (!_current_player)+1 << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }   
}