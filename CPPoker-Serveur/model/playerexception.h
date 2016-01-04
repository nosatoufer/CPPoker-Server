#ifndef PLAYEREXCEPTION_H
#define PLAYEREXCEPTION_H

#include <exception>
#include <string>

/**
 * @brief The PlayerException class is an exception class for the PokerPlayer class
 */
class PlayerException : public std::exception
{
private:
    std::string m_phrase;

public:
    PlayerException(std::string const& m_phrase) throw();
    virtual ~PlayerException() throw();

    /**
     * @brief what is an accessor to the error message
     * @return error message that cause the exception
     */
    virtual const char* what() const throw();
};

#endif // PLAYEREXCEPTION_H
