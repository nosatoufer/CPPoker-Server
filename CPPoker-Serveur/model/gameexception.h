#ifndef GAMEEXCEPTION_H
#define GAMEEXCEPTION_H

#include <exception>
#include <string>

/**
 * @brief The GameException class is an exception class for the class GamePoker
 */
class GameException : public std::exception
{
private:
    std::string m_phrase;

public:
    GameException(std::string const& m_phrase) throw();
    virtual ~GameException() throw();

    /**
     * @brief what is an accessor to the error message
     * @return error message that cause the exception
     */
    virtual const char* what() const throw();
};

#endif // GAMEEXCEPTION_H
