#include<iostream>
using namespace std;
#include"Piece.h"
#include"Move.h"
#include"Pawn.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include "Player.h"
#include "Board.h"
#include"Chess.h"
#include"Queen.h"
#include"King.h"
#include"Camel.h"
#include"Colouring.h"

int main()
{
	Chess c1;
	string arr[] = { "\n\n\n\t\t\t\t\t1.Play Chess","\n\t\t\t\t\t2.Play King Rush","\n\t\t\t\t\t3.Play Tal's Gambit","\n\t\t\t\t\t4.Exit"};
	int num= complete_menu(arr, 4);
	string arr2[] = { "\n\n\n\t\t\t\t\t1.New Game","\n\n\n\t\t\t\t\t2. Load a previous game" };
	int num1=1;
	bool check=1;
	system("color 09");
	switch (num)
	{
	case 1:
		
		num1 = complete_menu(arr2, 2);
		if (num1 == 1)
		c1.b1.createboard1();
		else
			check = Board::readfromfile(c1.b1, "Chess1.txt");
		if (check == 0)
			main();
		else
		c1.playchess();
		break;
	case 2:
		 num1 = complete_menu(arr2, 2);
		if (num1 == 1)
			c1.b1.createboard3();
		else
		check=	Board::readfromfile(c1.b1, "Chess2.txt");
		if (check == 0)
			main();
		else
		c1.playkingrush();
		break;
	case 3:
		 num1 = complete_menu(arr2, 2);
		if (num1 == 1)
			c1.b1.createboard2();
		else
			check = Board::readfromfile(c1.b1, "Chess3.txt");
		if (check == 0)
			main();
		else
		c1.playtalgambit();
		break;
	case 4:
		exit(0);
		
	}
	main();
	


}

//
//#define CPPHTTPLIB_OPENSSL_SUPPORT
//#include <iostream>
//#include "httplib.h"
//#include "./nlohmann/json.hpp"
//#include <string>
//using namespace std;
//using json = nlohmann::json;
//
//int main() {
//	try {
//		httplib::SSLClient client("stockfish.online");
//
//		string fen = "r1bqkbnr/pppp1ppp/2n5/1B2p3/4P3/5N2/PPPP1PPP/RNBQK2R b KQkq - 3 3";
//		string depth = "5";
//
//		string path = "/api/s/v2.php?fen=" + fen + "&depth=" + depth;
//
//		httplib::Headers headers = {
//
//			{"Accept", "application/json"}
//
//		};
//		auto response = client.Get(path.c_str(), headers);
//		json data = json::parse(response->body);
//		if (response && response->status == 200) {
//			cout << response->body << endl;
//
//			string move = data["bestmove"];
//			string a = move.substr(9, 2);
//			cout << a;
//		}
//		else {
//			cout << "Error: " << (response ? response->status : -1) << endl;
//			if (response) cout << "Response body: " << response->body << endl;
//		}
//	}
//	catch (...) {
//		cerr << "Unknown error!" << endl;
//	}
//	return 0;
//}