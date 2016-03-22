#include "ChessMove.h"

namespace chess {

ChessMove::ChessMove(Vec2 p_direction, int p_max_num)
  : direction(p_direction),
    max_num(p_max_num)
{
}

ChessMove::~ChessMove()
{
}

} // namespace chess.
