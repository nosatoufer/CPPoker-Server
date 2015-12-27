#include "playerexception.h"

PlayerException::PlayerException(std::string const& phrase="") throw(): phrase(phrase) {}

PlayerException::~PlayerException() throw() {}

const char* PlayerException::what() const throw()
{
    return this->phrase.c_str();
}
