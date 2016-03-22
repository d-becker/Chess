#ifndef DEFAULT_CHESS_BOARD_H
#define DEFAULT_CHESS_BOARD_H

#include "ChessBoard.h"

#include <vector>

#include "Patch.h"

namespace chess {

class DefaultChessBoard : public ChessBoard
{
public:
  DefaultChessBoard(int width, int height);
  virtual ~DefaultChessBoard();

  virtual int getWidth() const override;
  virtual int getHeight() const override;

  virtual const ChessPiece* get(int file, int rank) const override;
  using ChessBoard::get;

  virtual void set(int file, int rank, const ChessPiece* piece) override;
  using ChessBoard::set;
  
  virtual bool apply(const Patch& patch) override;
  virtual bool revert(const Patch& patch) override;

  virtual std::shared_ptr<ChessBoard> clone() const override;
private:
  const int m_width;
  const int m_height;

  std::vector<std::vector<const ChessPiece*>> m_board;
};

} // namespace chess.

#endif // DEFAULT_CHESS_BOARD_H
