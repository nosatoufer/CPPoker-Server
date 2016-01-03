#ifndef ROOMMANAGEREXCEPTION_H
#define ROOMMANAGEREXCEPTION_H

#include <exception>
#include <string>

class RoomManagerException : public std::exception
{
private:
    std::string phrase;

public:
    RoomManagerException(std::string const& phrase) throw();
    virtual ~RoomManagerException() throw();

    virtual const char* what() const throw();
};

#endif // ROOMMANAGEREXCEPTION_H
