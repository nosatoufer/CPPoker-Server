#include "gameexception.h"

GameException::GameException(std::string const& phrase="") throw(): m_phrase(phrase) {}

GameException::~GameException() throw() {}

const char* GameException::what() const throw()
{
    return this->m_phrase.c_str();
}
