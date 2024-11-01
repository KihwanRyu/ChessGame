#include <iostream>
#include <string>
#include <cmath>
#include <memory>

template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

class Piece {
public:
    virtual bool isValidMove(int srcRow, int srcCol, int destRow, int destCol) = 0;
    virtual std::string getName() = 0;
    virtual ~Piece() = default;
};

class King : public Piece {
public:
    bool isValidMove(int srcRow, int srcCol, int destRow, int destCol) override {
        return abs(destRow - srcRow) <= 1 && abs(destCol - srcCol) <= 1;
    }
    std::string getName() override { return "King"; }
};

class Queen : public Piece {
public:
    bool isValidMove(int srcRow, int srcCol, int destRow, int destCol) override {
        return (srcRow == destRow || srcCol == destCol || abs(destRow - srcRow) == abs(destCol - srcCol));
    }
    std::string getName() override { return "Queen"; }
};

class Rook : public Piece {
public:
    bool isValidMove(int srcRow, int srcCol, int destRow, int destCol) override {
        return (srcRow == destRow || srcCol == destCol);
    }
    std::string getName() override { return "Rook"; }
};

class Bishop : public Piece {
public:
    bool isValidMove(int srcRow, int srcCol, int destRow, int destCol) override {
        return abs(destRow - srcRow) == abs(destCol - srcCol);
    }
    std::string getName() override { return "Bishop"; }
};

class Knight : public Piece {
public:
    bool isValidMove(int srcRow, int srcCol, int destRow, int destCol) override {
        return (abs(destRow - srcRow) == 2 && abs(destCol - srcCol) == 1) || 
               (abs(destRow - srcRow) == 1 && abs(destCol - srcCol) == 2);
    }
    std::string getName() override { return "Knight"; }
};

class Pawn : public Piece {
public:
    bool isValidMove(int srcRow, int srcCol, int destRow, int destCol) override {
        return (destRow - srcRow == 1 && srcCol == destCol);  // 기본적인 전진만 가능
    }
    std::string getName() override { return "Pawn"; }
};
