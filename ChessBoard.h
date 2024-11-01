#include <map>
#include <memory>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include "Piece.h"

class ChessBoard {
private:
    std::map<std::pair<int, int>, std::unique_ptr<Piece> > board;
    std::set<std::string> capturedPieces;
    std::stack<std::pair<std::pair<int, int>, std::pair<int, int> > > moveHistory;
    std::queue<std::string> playersTurn;

public:
    ChessBoard() { initializeBoard(); playersTurn.push("White"); playersTurn.push("Black"); }

    void initializeBoard() {
        board[std::make_pair(0, 4)] = make_unique<King>();
        board[std::make_pair(1, 4)] = make_unique<Pawn>();
        board[std::make_pair(6, 4)] = make_unique<Pawn>();
        board[std::make_pair(7, 4)] = make_unique<King>();
    }

    bool movePiece(int srcRow, int srcCol, int destRow, int destCol) {
        auto srcPos = std::make_pair(srcRow, srcCol);
        auto destPos = std::make_pair(destRow, destCol);

        if (board[srcPos] && board[srcPos]->isValidMove(srcRow, srcCol, destRow, destCol)) {
            capturedPieces.insert(board[destPos] ? board[destPos]->getName() : "");
            moveHistory.push({srcPos, destPos});
            board[destPos] = std::move(board[srcPos]);
            board.erase(srcPos);
            playersTurn.push(playersTurn.front());
            playersTurn.pop();
            return true;
        }
        std::cout << "Invalid move.\n";
        return false;
    }

    void printBoard() {
        for (int row = 0; row < 8; ++row) {
            for (int col = 0; col < 8; ++col) {
                auto pos = std::make_pair(row, col);
                if (board[pos]) {
                    std::cout << board[pos]->getName()[0] << " ";
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << "\n";
        }
    }

    bool isGameOver() {
        // 왕의 위치를 확인하여 체크 상태를 감지하거나 체크메이트 여부를 판단할 수 있습니다.
        return false;
    }
};
