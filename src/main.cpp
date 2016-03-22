#include <iostream>

#include "ChessBoard.h"
#include "ChessPiece.h"
#include "DefaultChessBoard.h"
#include "Vec2.h"
#include "Patch.h"

using namespace std;
using namespace chess;

void print_chess_board(const ChessBoard& cb)
{
  int width = cb.getWidth();
  int height = cb.getHeight();
  cout << "Size: " << width << "x" << height << "\n";
  for (int i = height; i > 0; --i)
    {
      for (int j = 1; j <= width; ++j)
	{
	  cout << cb.get(i, j) << "\t";
	}
      cout << "\n";
    }
}

int main() {
  cout << "Hello World.\n";
  ChessBoard* cb = new DefaultChessBoard(8, 8);
  ChessPiece* cp = new ChessPiece(true);
  cb->set(1, 1, cp);
  print_chess_board(*cb);
  return 0;
}

