cmake_minimum_required (VERSION 2.8)

set(SRC_FILES main.cpp
			  DefaultChessBoard.cpp
			  GameState.cpp
			  ChessMove.cpp
			  ChessPiece.cpp
   )

add_executable(Chess ${SRC_FILES})
