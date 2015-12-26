#include "roomexception.h"

RoomException::RoomException(std::string const& phrase="") throw(): phrase(phrase) {}

RoomException::~RoomException() throw() {}

const char* RoomException::what() const throw()
{
    return this->phrase.c_str();
}
