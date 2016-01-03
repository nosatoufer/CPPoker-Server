#ifndef POKERMANAGEREXCEPTION_H
#define POKERMANAGEREXCEPTION_H

#include <exception>
#include <string>

class PokerManagerException : public std::exception
{
private:
    std::string phrase;

public:
    PokerManagerException(std::string const& phrase) throw();
    virtual ~PokerManagerException() throw();

    virtual const char* what() const throw();
};

#endif // POKERMANAGEREXCEPTION_H
