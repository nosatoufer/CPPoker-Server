#include "roommanagerexception.h"

RoomManagerException::RoomManagerException(std::string const& phrase="") throw(): phrase(phrase) {}

RoomManagerException::~RoomManagerException() throw() {}

const char* RoomManagerException::what() const throw()
{
    return this->phrase.c_str();
}
