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

    virtual bool empty();

    virtual bool isSet(const std::string &s);

    virtual void setCommand(Command i);
    virtual void setStatus(const std::string s);
    virtual void setMessage(std::string s);
    virtual void set(std::string key, std::string value);
    virtual void setMap(std::string key, std::map<std::string,std::string> m);

    virtual Command getCommand();
    virtual std::string getStatus();
    virtual std::string getMessage();
    virtual std::string get(std::string s);
    virtual std::map<std::string, std::string> getMap(std::string s);

    virtual ~Request();
};

#endif // REQUEST_H
