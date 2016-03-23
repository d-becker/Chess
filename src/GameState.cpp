#include "GameState.h"

#include <stdexcept>

namespace chess {

GameState::GameState(std::shared_ptr<ChessBoard> board)
  : m_board(board)
{
  if (!m_board)
    throw std::invalid_argument("A null pointer is not allowed.");
}

GameState::GameState(const GameState& other)
  : m_board(other.m_board->clone()),
    m_history(other.m_history),
    m_cursor(other.m_cursor)
{
}

GameState::~GameState()
{
}

int GameState::getCursorPosition() const
{
  return m_cursor;
}

int GameState::numberOfPatches() const
{
  return m_history.size();
}

bool GameState::applyPatch(Patch patch)
{
  bool applied = m_board->apply(patch);
  if (applied)
  {
    ++m_cursor;
    if (m_history.size() > m_cursor)
    {
      m_history.erase(m_history.begin() + m_cursor, m_history.end());
    }

    return true;
  }

  return false;
}

bool GameState::forward()
{
  if (m_cursor < m_history.size() && m_cursor >= 0)
  {
    bool applied =  m_board->apply(m_history.at(m_cursor));
    if (applied)
      ++m_cursor;

    return applied;
  }

  return false;
}

bool GameState::back()
{
  const int previous = m_cursor - 1;
  if (previous < m_history.size() && previous >= 0)
  {
    bool reverted =  m_board->revert(m_history.at(previous));
    if (reverted)
      --m_cursor;

    return reverted;
  }

  return false;
}

} // namespace chess.
