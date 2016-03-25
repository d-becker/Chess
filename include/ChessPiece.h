#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include <string>
#include <vector>

#include "GameState.h"
#include "Patch.h"
#include "Vec2.h"

namespace chess {

/**
 * A base class representing chess pieces. The individual chess piece types
 * should be subclasses of this class.Instances of those classes are meant to be
 * immutable and there should be only one instance per chess piece type.
 * The chess board should hold pointers to the pieces, not the \c ChessPiece
 * objects themselves.
 */

class ChessPiece
{
public:
  virtual ~ChessPiece();

  bool isWhite() const;  
  std::string toString() const;

  std::vector<Patch> getMovePatches(const GameState& game_state,
				    const Vec2& pos) const;
  
protected:
  ChessPiece(std::string abbrev,
	     bool white);

private:
  std::string m_abbrev;
  bool m_white;
};

} // namespace chess.

#endif // CHESS_PIECE_H
