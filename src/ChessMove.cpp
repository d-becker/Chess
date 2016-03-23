#include "ChessMove.h"

namespace chess {

ChessMove::ChessMove(Vec2 p_direction,
		     int p_max_num,
		     std::vector<std::function<bool(
		       std::shared_ptr<GameState>,
		       const Vec2&)>> conditions)
  : direction(p_direction),
    max_num(p_max_num),
    m_conditions(conditions)
{
}

ChessMove::~ChessMove()
{
}

bool ChessMove::conditionsOk(std::shared_ptr<GameState> game_state,
			     const Vec2& pos) const
{
  for (const auto& condition : m_conditions)
  {
    if (!condition(game_state, pos))
      return false;
  }

  return true;
}

} // namespace chess.
