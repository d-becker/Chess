#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>
#include <vector>

#include "ChessBoard.h"
#include "Patch.h"

namespace chess {

/**
 * This class stores the game state with the standing on the board and the
 * patches that have been applied since the beginning of the game (that is,
 * a history of the moves that have been taken by the players. It is possible
 * to go back to a previous state by reverting patches, and then go forward
 * again by re-applying the patches. If, after going back to a previous state,
 * a new patch is applied instead of going forward, all of the following patches
 * are deleted and the new patch becomes the most recent one. 
 */
class GameState
{
public:
  GameState(std::shared_ptr<ChessBoard> board);
  virtual ~GameState();

  GameState(const GameState& other);

  std::shared_ptr<const ChessBoard> getBoard() const;

  /**
   * Returns the index of the patch that is after
   * the most recently applied patch.
   *
   * \return The index of the patch that is after
   *         the most recently applied patch.
   */
  int getCursorPosition() const;

  /**
   * Returns the number of patches that are stored in the history.
   *
   * \return The number of patches that are stored in the history.
   */
  int numberOfPatches() const;

  /**
   * Applies the given patch if it is possible.
   *
   * \param patch The patch too apply.
   *
   * \return \c true if the patch was applied;
   *         \c false if it was not possible to apply the patch.
   */
  bool applyPatch(Patch patch);

  /**
   * Applies the next cached patch if there is one.
   *
   * \return \c true if a cached patch existed (and was applied) after
   *         the most recently applied one; \c false otherwise.
   */
  bool forward();

  
  /**
   * Reverts the most recent non-reverted patch if there is one.
   *
   * \return \c true if a cached non-reverted patch existed (and was reverted);
   *         \c false otherwise.
   */
  bool back();
private:
  const std::shared_ptr<ChessBoard> m_board;
  std::vector<Patch> m_history;

  // Stores the index of the patch that is one after the most recently applied patch.
  int m_cursor;
};

} // namespace chess.

#endif // GAME_STATE_H
