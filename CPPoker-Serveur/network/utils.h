#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <map>
#include <string.h>
#include <sstream>
#include <iostream>
#include <exception>

std::string addSlashes(const std::string str) ;
std::string stripSlashes(const std::string str);

std::map<std::string, std::string> jsonDecode(const std::string str);
std::string jsonEncode(const std::map<std::string, std::string> m);

#endif // UTILS_H
