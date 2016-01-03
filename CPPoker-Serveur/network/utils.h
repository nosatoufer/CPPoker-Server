#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <map>
#include <string.h>
#include <sstream>
#include <iostream>
#include <exception>

/**
 * @brief addSlashes escape charceter from string
 * @param str string
 * @return
 */
std::string addSlashes(const std::string str) ;
/**
 * @brief stripSlashes delete escaping charceter from string
 * @param str string
 * @return
 */
std::string stripSlashes(const std::string str);

/**
 * @brief jsonDecode decode a string to a map
 * @param str string to decode
 * @return map decoded
 */
std::map<std::string, std::string> jsonDecode(const std::string str);
/**
 * @brief jsonEncode encode a map to a string
 * @param m map to encode
 * @return string encoded
 */
std::string jsonEncode(const std::map<std::string, std::string> m);

#endif // UTILS_H
