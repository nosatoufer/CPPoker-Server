#include "pokermanagerexception.h"

PokerManagerException::PokerManagerException(std::string const& phrase="") throw(): m_phrase(phrase) {}

PokerManagerException::~PokerManagerException() throw() {}

const char* PokerManagerException::what() const throw()
{
    return this->m_phrase.c_str();
}
