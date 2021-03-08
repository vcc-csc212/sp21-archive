#include <iostream>

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class ttt_game
{
	public:
		//default constructor, sets ai_mode to false
		ttt_game();

		//constructor, bool ai_mode tells whether ai mode should be enabled
		ttt_game(bool ai_mode);

		//default destructor
		~ttt_game();

		//executes game
		void play();

	private:
		struct game_state {
			char* _gs_board;
			int _gs_player;
		};

		//holds current player
		int _current_player;

		//tic tac toe gameboard to hold moves
		char* _board;

		//true if AI mode enabled, false otherwise
		bool _ai_mode;

		//-1 if ongoing, 0 if over with tie, 1 if over with win
		int game_status(char* board);

		//draws board and returns it as a string
		std::string draw_board(char* board);

		//makes a move for the current player, returns true on success, false on invalid move
		bool make_move(int location);

		//minimax algorithm to calculate the minimax value of state, P1 is max, P2 is min
		int minimax_algo(game_state* state, int depth);

		//returns optimal move for ai using minimax algorithm
		int minimax_move();
};

#endif