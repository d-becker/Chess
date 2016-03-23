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
	    int p_max_num,
	    std::vector<std::function<bool(std::shared_ptr<GameState>,
					   const Vec2&)>> conditions);
  virtual ~ChessMove();

  /*
   * Returns \c true if the this move can be taken with the specified
   * game state and by the piece at position \a pos.
   *
   * \param game_state The current game state.
   * \param pos The position of the piece that is to take the move.
   *
   * \return \c true if the move can be taken; \c false otherwise.
   */
  bool conditionsOk(std::shared_ptr<GameState> game_state,
		    const Vec2& pos) const;

  const Vec2 direction;

  // The maximum number this step can be taken in a row - 0 means infinity.
  const int max_num;

private:
  const std::vector<std::function<bool(std::shared_ptr<GameState>,
				       const Vec2&)>> m_conditions;
};

} // namespace chess.

#endif // CHESS_MOVE_H
