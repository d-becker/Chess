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
  ChessPiece* active;
  Vec2 active_before;
  Vec2 active_after;

  ChessPiece* passive;
  Vec2 passive_before;
  Vec2 passive_after;
};

} // namespace chess.

#endif // PATCH_H
