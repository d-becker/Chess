#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <memory>

#include "Vec2.h"

namespace chess {

class ChessPiece;
class Patch;

/**
 * This is an interface that represents a chess board.
 * A field has two coordinates: the first is the file number (the
 * horizontal axis), the second is the rank number (the vertical axis).
 * As on a normal chess board, the origin is (1, 1) or (A, 1) in the bottom left
 * corner, with the coordinates growing to the right and upwards.
 */
class ChessBoard
{
public:
  ChessBoard() {}
  virtual ~ChessBoard() {}

  /**
   * Returns the number of files on the board.
   *
   * \return The number of files on the board.
   */ 
  virtual int getWidth() const = 0;

  /**
   * Returns the number of ranks on the board.
   *
   * \return The number of ranks on the board.
   */
  virtual int getHeight() const = 0;
  
  /**
   * Returns a pointer to the \c ChessPiece that is on the given field.
   * If the given field is not a valid field or if there is no chess piece
   * on that field, a null pointer is returned.
   *
   * \param file The number of the file of the field.
   * \param rank The number of the rank of the field.
   *
   * \return A pointer to the \c ChessPiece that is on the given field.
   */
  virtual const ChessPiece* get(int file, int rank) const = 0;

  /**
   * See \c get(int,int) for details.
   */
  virtual const ChessPiece* get(const Vec2& pos) const
  {
    return get(pos.x, pos.y);
  }

  /**
   * Sets the \c ChessPiece that is on the given field to \a piece.
   * If the given field is not a valid field, nothing is done.
   *
   * \param file The number of the file of the field.
   * \param rank The number of the rank of the field.
   * \param piece The chess piece that will be on the field.
   */
  virtual void set(int file, int rank, const ChessPiece* piece) = 0;

  /**
   * See \c set(int,int,const ChessPiece*) for details.
   */
  virtual void set(const Vec2& pos, const ChessPiece* piece)
  {
    set(pos.x, pos.y, piece);
  }
  
  /**
   * Applies a patch on the chess board if it is possible, that is,
   * the situation described in the patch matches the board.
   * 
   * \param patch The patch to apply.
   *
   * \return \c true if the patch was applied;
   *         \c false if it was not possible to apply the patch.
   */
  virtual bool apply(const Patch& patch) = 0;


  /**
   * Reverts a patch on the chess board if it is possible, that is,
   * the situation described in the patch matches the board.
   * 
   * \param patch The patch to revert.
   *
   * \return \c true if the patch was reverted;
   *         \c false if it was not possible to apply the patch.
   */

  virtual bool revert(const Patch& patch) = 0;

  /**
   * Returns \c true if the given field is a valid field on the board.
   *
   * \param file The number of the file of the field.
   * \param rank The number of the rank of the field.
   *
   * \return \c true if the given field is a valid field on the board;
   *         \c false otherwise.
   */
  virtual bool isValidField(int file, int rank) const
  {
    return file >= 1 && file <= getWidth()
             && rank >= 1 && rank <= getHeight();
  }

  /**
   * Returns a polymorphic copy of this \c ChessBoard.
   *
   * \return  A polymorphic copy of this \c ChessBoard.
   */
  virtual std::shared_ptr<ChessBoard> clone() const = 0;
};

} // namespace chess.

#endif // CHESS_BOARD_H
