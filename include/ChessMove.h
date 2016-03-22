#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

#include "Vec2.h"

namespace chess {
class ChessMove
{
public:
  ChessMove(Vec2 p_direction, int p_max_num);
  virtual ~ChessMove();

  const Vec2 direction;

  // The maximum number this step can be taken in a row - 0 means infinity.
  const int max_num;
};

} // namespace chess.

#endif // CHESS_MOVE_H
