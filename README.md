{\rtf1\ansi\ansicpg949\cocoartf2818
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 HelveticaNeue;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\deftab560
\pard\pardeftab560\slleading20\pardirnatural\partightenfactor0

\f0\fs26 \cf0 # Chess Game\
\
## Project Overview\
This project is a chess game implemented in C++. Players can move pieces according to chess rules and take turns to play the game.\
\
## STL Usage\
- **std::map**: Manages the positions on the board.\
- **std::set**: Stores captured pieces to prevent duplicates.\
- **std::stack**: Keeps track of move history for undo functionality.\
- **std::queue**: Manages the players' turns.\
\
## Code Structure\
- `Piece.h`: Defines the classes for chess pieces and their movement rules.\
- `ChessBoard.h`: Manages the state of the chessboard and the pieces.\
- `GameController.h`: Controls the flow of the game.\
- `main.cpp`: The entry point of the program.\
\
## Future Improvements\
- Add check and checkmate functionality.\
- Implement various game modes.\
}