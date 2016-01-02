#include "request.h"

const std::string Request::COMMAND = "__command";
const std::string Request::STATUS = "__status";
const std::string Request::MESSAGE = "__message";
const std::string Request::STATUS_SUCCESS = "S";
const std::string Request::STATUS_FAILURE = "F";

Request::Request() {}

Request::Request(std::string s) {
    values = jsonDecode(s);
}

Request::Request(std::map<std::string, std::string> m) :
    values(m)
{}

std::string& Request::operator[](std::string s){
    return values[s];
}

Request::operator std::string () {
    return jsonEncode(values);
}

std::string Request::toString() {
    return jsonEncode(values);
}

bool Request::empty() {
    return values.empty();
}

bool Request::isSet(const std::string &s) {
    return (values.find(s) != values.end());
}

Command Request::getCommand(){
    std::string s = values[Request::COMMAND];
    Command res = atoi(s.c_str());
    return res;
}

std::string Request::getStatus() {
    return values[Request::STATUS];
}

std::string Request::get(std::string s) {
    return values[s];
}

std::string Request::getMessage() {
    return values[Request::MESSAGE];
}

std::map<std::string, std::string> Request::getMap(std::string s) {
    return jsonDecode(values[s]);
}

void Request::setCommand(Command i) {
    std::ostringstream s;
    s<<i;
    values[Request::COMMAND] = s.str();
}

void Request::setStatus(const std::string s) {
    values[Request::STATUS] = s;
}

void Request::setMessage(std::string s) {
    values[Request::MESSAGE] = s;
}

void Request::set(std::string key, std::string value) {
    values[key] = value;
}

void Request::setMap(std::string key, std::map<std::string,std::string> m) {
    values[key] = jsonEncode(m);
}

Request::~Request() {}

Request *Request::createRequest(Command cmd, std::string msg)
{
    Request * req = new Request();
    req->setCommand(cmd);
    req->setMessage(msg);
    return req;
}

Request *Request::usedNickname()
{
    Request * req = new Request();
    req->setCommand(NICK_USED);
    return req;
}
