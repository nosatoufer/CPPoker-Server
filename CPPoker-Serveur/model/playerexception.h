#ifndef PLAYEREXCEPTION_H
#define PLAYEREXCEPTION_H

#include <exception>
#include <string>

class PlayerException : public std::exception
{
private:
    std::string phrase;

public:
    PlayerException(std::string const& phrase) throw();
    virtual ~PlayerException() throw();

    virtual const char* what() const throw();
};

#endif // PLAYEREXCEPTION_H
