#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

#include <functional>
#include <memory>
#include <vector>

#include "GameState.h"
#include "Vec2.h"

namespace chess {

typedef std::function<bool(const GameState&, const Vec2&)> Condition;

class ChessMove
{
public:
  ChessMove(Vec2 p_movement_vector,
	    int p_max_num,
	    std::vector<Condition> conditions);
  virtual ~ChessMove();

  /**
   * Returns \c true if the this move can be taken with the specified
   * game state and by the piece at position \a pos.
   *
   * \param game_state The current game state.
   * \param pos The position of the piece that is to take the move.
   * \param would_capture An output parameter that will be set to \c true
   *        if taking the move is possible and would capture a piece;
   *        if taking the move is possible and would not capture, this parameter
   *        will be set to \c false. If taking the move is not possible,
   *        the parameter will not be modified.
   *
   * \return \c true if the move can be taken; \c false otherwise.
   */
  bool canMakeMove(const GameState& game_state,
		   const Vec2& pos,
		   bool& would_capture) const;
  
  /**
   * A 2D vector from the current position of the piece
   * to the new position after taking this move (if possible).
   */
  const Vec2 movement_vector;

  /**
   * The maximum number this step can be taken in a row - 0 means infinity.
   */
  const int max_num;

private:
  std::vector<Condition> m_conditions;
};

} // namespace chess.

#endif // CHESS_MOVE_H
