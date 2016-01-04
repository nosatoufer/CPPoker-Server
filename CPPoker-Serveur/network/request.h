#ifndef REQUEST_H
#define REQUEST_H

#include <map>
#include <string.h>
#include <iostream>
#include "utils.h"
#include "commands.h"
#include <stdlib.h>
#include <sstream>

class Request{
private:
    std::map<std::string, std::string> values;

public:
    static const std::string COMMAND;
    static const std::string STATUS;
    static const std::string MESSAGE;

    static const std::string STATUS_SUCCESS;
    static const std::string STATUS_FAILURE;

    Request();

    Request(std::string s);

    Request(std::map<std::string, std::string> m);

    virtual std::string & operator[](std::string s);

    virtual operator std::string ();

    virtual std::string toString();

    /**
     * @brief empty checks if the request is empty
     * @return true if the request is empty
     */
    virtual bool empty();

    /**
     * @brief isSet check if there is an entry of the given key in the map
     * @param s the key to check
     * @return true if the key exists
     */
    virtual bool isSet(const std::string &s);

    /**
     * @brief setCommand sets the command to the request
     * @param i the command to set
     */
    virtual void setCommand(Command i);

    /**
     * @brief setStatus sets the status to the request
     * @param s the status
     */
    virtual void setStatus(const std::string s);

    /**
     * @brief setMessage sets a message to the request
     * @param s the message
     */
    virtual void setMessage(std::string s);

    /**
     * @brief set adds a key and a value to the map
     * @param key the key
     * @param value the value
     */
    virtual void set(std::string key, std::string value);

    /**
     * @brief setMap adds a map as a value
     * @param key the key of the map
     * @param m the map
     */
    virtual void setMap(std::string key, std::map<std::string,std::string> m);

    /**
     * @brief getCommand returns the command
     * @return the command
     */
    virtual Command getCommand();

    /**
     * @brief getStatus returns the status
     * @return the status
     */
    virtual std::string getStatus();

    /**
     * @brief getMessage returns the message
     * @return the message
     */
    virtual std::string getMessage();

    /**
     * @brief get returns the first value linked to the given key
     * @param s the key
     * @return the value
     */
    virtual std::string get(std::string s);

    /**
     * @brief getMap return the map linked to the given key
     * @param s the key
     * @return the map
     */
    virtual std::map<std::string, std::string> getMap(std::string s);

    virtual ~Request();


};

#endif // REQUEST_H
