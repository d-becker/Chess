#ifndef PATCH_H
#define PATCH_H

#include "Vec2.h"

namespace chess {

class ChessPiece;

/*
 * This struct is a patch on a chess board that stores modifications,
 * mainly used when making chess moves. A chess board can apply
 * or revert these patches.
 */
struct Patch
{
  Patch(ChessPiece* p_active,
	Vec2 p_active_before,
	Vec2 p_active_after,

	ChessPiece* p_passive,
	Vec2 p_passive_before,
	Vec2 p_passive_after)
    : active(p_active),
      active_before(p_active_before),
      active_after(p_active_after),

      passive(p_passive),
      passive_before(p_passive_before),
      passive_after(p_passive_after)
  {
  }
  
  ChessPiece* active;
  Vec2 active_before;
  Vec2 active_after;

  ChessPiece* passive;
  Vec2 passive_before;
  Vec2 passive_after;
};

} // namespace chess.

#endif // PATCH_H
