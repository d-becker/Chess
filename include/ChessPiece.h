#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

namespace chess {

/*
 * A base class representing chess pieces. The individual chess piece types
 * should be subclasses of this class.Instances of those classes are meant to be
 * immutable and there should be only one instance per chess piece type.
 * The chess board should hold pointers to the pieces, not the @c ChessPiece
 * objects themselves.
 */

class ChessPiece
{
public:
  ChessPiece(bool white);
  virtual ~ChessPiece();

  bool isWhite() const;
private:
  bool m_white;
};

} // namespace chess.

#endif // CHESS_PIECE_H
