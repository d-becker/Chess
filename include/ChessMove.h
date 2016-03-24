#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

#include <functional>
#include <memory>
#include <vector>

#include "GameState.h"
#include "Vec2.h"

namespace chess {

class ChessMove
{
public:
  ChessMove(Vec2 p_direction,
	    int p_max_num)
    : direction(p_direction),
      max_num(p_max_num)
  {
  }

  virtual ~ChessMove() {}

  /**
   * Returns \c true if the this move can be taken with the specified
   * game state and by the piece at position \a pos.
   *
   * \param game_state The current game state.
   * \param pos The position of the piece that is to take the move.
   * \param would_capture An output parameter that will be set to \c true
   *        if taking the move would capture a piece and \c false otherwise.
   *
   * \return \c true if the move can be taken; \c false otherwise.
   */
  virtual bool canMakeMove(std::shared_ptr<GameState> game_state,
			   const Vec2& pos,
			   bool& would_capture) const = 0;

  /**
   * Returns a polymorphic copy of this \c ChessMove object.
   *
   * \return A polymorphic copy of this \c ChessMove object.
   */
  virtual std::shared_ptr<ChessMove> clone() const = 0;
  
  /**
   * Returns a 2D vector from the current position of the piece
   * to the new position after taking this move (if possible).
   *
   * \return A 2D vector from the current position of the piece
   *         to the new position after taking this move (if possible).
   */
  const Vec2 getMovementVector() const = 0;

  /**
   * Returns the maximum number this step can be taken in a row - 0 means
   * infinity.
   *
   * \return The maximum number this step can be taken in a row - 0 means
   *         infinity.
   */
  const int getMaxNum() const = 0;
};

} // namespace chess.

#endif // CHESS_MOVE_H
