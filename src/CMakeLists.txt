cmake_minimum_required (VERSION 2.8)

set(SRC_FILES main.cpp
			  ChessPiece.cpp
			  DefaultChessBoard.cpp
			  ChessMove.cpp
			  GameState.cpp
   )

add_executable(Chess ${SRC_FILES})
