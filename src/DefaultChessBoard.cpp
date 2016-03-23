#include "DefaultChessBoard.h"

namespace chess {

DefaultChessBoard::DefaultChessBoard(int width, int height)
  : ChessBoard(),
    m_width(width),
    m_height(height),
    m_board(width, std::vector<const ChessPiece*>(height))
{
}

DefaultChessBoard::~DefaultChessBoard()
{
}

int DefaultChessBoard::getWidth() const
{
  return m_width;
}

int DefaultChessBoard::getHeight() const
{
  return m_height;
}

const ChessPiece* DefaultChessBoard::get(int file, int rank) const
{
  if (!isValidField(file, rank))
    return nullptr;

  return m_board.at(file - 1).at(rank - 1);
}

void DefaultChessBoard::set(int file, int rank, const ChessPiece* piece)
{
  if (!isValidField(file, rank))
    return;

  m_board.at(file - 1).at(rank - 1) = piece;
}

bool DefaultChessBoard::apply(const Patch& patch)
{
  // Checking if the situation described by the patch matches the chess board.
  if (get(patch.active_before) != patch.active
      || get(patch.passive_before) != patch.passive)
    return false;

  // Taking the pieces down.
  set(patch.active_before, nullptr);
  set(patch.passive_before, nullptr);

  // Putting the pieces to their new place.
  set(patch.active_after, patch.active);
  set(patch.passive_after, patch.passive);

  return true;
}

bool DefaultChessBoard::revert(const Patch& patch)
{
    // Checking if the situation described by the patch matches the chess board.
  if (get(patch.active_after) != patch.active
      || get(patch.passive_after) != patch.passive)
    return false;

  // Taking the pieces down.
  set(patch.active_after, nullptr);
  set(patch.passive_after, nullptr);

  // Putting the pieces back to their old place.
  set(patch.active_before, patch.active);
  set(patch.passive_before, patch.passive);

  return true;
}

std::shared_ptr<ChessBoard> DefaultChessBoard::clone() const
{
  return std::make_shared<DefaultChessBoard>(*this);
}

} // namespace chess.
