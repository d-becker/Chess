#include <ChessPiece.h>

namespace chess {

ChessPiece::ChessPiece(std::string abbrev,
		       bool white)
  : m_abbrev(abbrev),
    m_white(white)
{
}

ChessPiece::~ChessPiece()
{
}

bool ChessPiece::isWhite() const
{
  return m_white;
}

std::string ChessPiece::toString() const
{
  return m_abbrev;
}

std::vector<Patch> ChessPiece::getMovePatches(const GameState& game_state,
					      const Vec2& pos) const
{
  // TODO.
}

} // namespace chess.
