#include "ChessMove.h"

#include "ChessPiece.h"

namespace chess {

ChessMove::ChessMove(Vec2 p_movement_vector,
		     int p_max_num,
		     std::vector<Condition> conditions)
  : movement_vector(p_movement_vector),
    max_num(p_max_num),
    m_conditions(conditions)
{
}

ChessMove::~ChessMove()
{
}

bool ChessMove::canMakeMove(const GameState& game_state,
			    const Vec2& pos,
			    bool& would_capture) const
{
  const ChessPiece* moving_piece = game_state.getBoard()->get(pos);
  if (!moving_piece)
    return false;

  for (Condition condition : m_conditions)
  {
    if (!condition(game_state, pos))
      return false;
  }

  // Determining if the move would be a capture.
  bool moving_piece_white = moving_piece->isWhite();
  const ChessPiece* other_piece = game_state.getBoard()->get(pos + movement_vector);

  if (!other_piece || other_piece->isWhite() == moving_piece_white)
    would_capture = false;
  else
    would_capture = true;

  return true;  
}

} // namespace chess.
