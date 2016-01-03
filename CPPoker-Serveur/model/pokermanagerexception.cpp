#include "pokermanagerexception.h"

PokerManagerException::PokerManagerException(std::string const& phrase="") throw(): phrase(phrase) {}

PokerManagerException::~PokerManagerException() throw() {}

const char* PokerManagerException::what() const throw()
{
    return this->phrase.c_str();
}
