#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <exception>
#include <string>

class GameException : public std::exception
{
private:
    std::string phrase;

public:
    GameException(std::string const& phrase) throw();
    virtual ~GameException() throw();

    virtual const char* what() const throw();
};

#endif // GAMEEXCEPTION_H
