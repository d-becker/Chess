#include <ChessPiece.h>

namespace chess {

ChessPiece::ChessPiece(bool white)
  : m_white(white)
{
}

ChessPiece::~ChessPiece()
{
}

bool ChessPiece::isWhite() const
{
  return m_white;
}

} // namespace chess.
