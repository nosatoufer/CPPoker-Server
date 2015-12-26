#include "gameexception.h"

GameException::GameException(std::string const& phrase="") throw(): phrase(phrase) {}

GameException::~GameException() throw() {}

const char* GameException::what() const throw()
{
    return this->phrase.c_str();
}
