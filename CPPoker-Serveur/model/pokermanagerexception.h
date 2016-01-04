#ifndef POKERMANAGEREXCEPTION_H
#define POKERMANAGEREXCEPTION_H

#include <exception>
#include <string>

/**
 * @brief The PokerManagerException class is an exception class for the PokerPlayer class
 */
class PokerManagerException : public std::exception
{
private:
    std::string m_phrase;

public:
    PokerManagerException(std::string const& m_phrase) throw();
    virtual ~PokerManagerException() throw();

    /**
     * @brief what is an accessor to the error message
     * @return error message that cause the exception
     */
    virtual const char* what() const throw();
};

#endif // POKERMANAGEREXCEPTION_H
