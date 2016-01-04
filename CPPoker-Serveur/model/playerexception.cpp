#include "playerexception.h"

PlayerException::PlayerException(std::string const& phrase="") throw(): m_phrase(phrase) {}

PlayerException::~PlayerException() throw() {}

const char* PlayerException::what() const throw()
{
    return this->m_phrase.c_str();
}
