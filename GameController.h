#include "ChessBoard.h"

class GameController {
private:
    ChessBoard chessBoard;
    std::string currentPlayer;

public:
    GameController() : currentPlayer("White") {}

    void playGame() {
        int srcRow, srcCol, destRow, destCol;
        while (!chessBoard.isGameOver()) {
            chessBoard.printBoard();
            std::cout << currentPlayer << "'s turn. Enter move (srcRow srcCol destRow destCol): ";
            std::cin >> srcRow >> srcCol >> destRow >> destCol;

            if (chessBoard.movePiece(srcRow, srcCol, destRow, destCol)) {
                currentPlayer = (currentPlayer == "White") ? "Black" : "White";
                std::cout << "Move successful.\n";
            } else {
                std::cout << "Move failed. Try again.\n";
            }
        }
        std::cout << "Game Over! " << currentPlayer << " loses.\n";
    }
};
