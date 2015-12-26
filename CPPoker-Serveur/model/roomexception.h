#ifndef ROOMEXCEPTION_H
#define ROOMEXCEPTION_H

#include <exception>
#include <string>

class RoomException : public std::exception
{
private:
    std::string phrase;

public:
    RoomException(std::string const& phrase) throw();
    virtual ~RoomException() throw();

    virtual const char* what() const throw();
};

#endif // ROOMEXCEPTION_H
