#include "utils.h"

std::string addSlashes(const std::string str) {
    std::string res = "";
    const char * chars = str.c_str();
    for (unsigned int i = 0; i < strlen(chars); ++i) {
        if (chars[i] == '\\' || chars[i] == '\"')
            res += "\\";
        res += chars[i];
    }
    return res;
}

std::string stripSlashes(const std::string str) {
    std::string res = "";
    const char * chars = str.c_str();
    for (unsigned int i = 0; i < strlen(chars); ++i) {
        if (chars[i] == '\\')
            ++i;
        res += chars[i];
    }
    return res;
}

std::map<std::string, std::string> jsonDecode(const std::string str) {
    std::map<std::string, std::string> res;
    const char * chars = str.c_str();
    char type;
    if (strlen(chars) != 0) {
        if (chars[0] == '{')
            type = '{';
        else if (chars[0] == '[')
            type = '[';
        else {
            res["value"] = stripSlashes(str);
            return res;
        }
        std::string buffer;
        std::string key;
        std::string value;
        int k = 0;
        for (unsigned int i = 1; i < strlen(chars); ++i) {
            if (chars[i] == '\"') {
                ++i;
                while (chars[i] != '\"') {
                    buffer += chars[i];
                    if (chars[i] == '\\') {
                        ++i;
                        buffer += chars[i];
                    }
                    ++i;
                }
            } else if (chars[i] == ':') {
                key = stripSlashes(buffer);
                buffer = "";
            } else if (chars[i] == ',' || chars[i] == '}') {
                value = stripSlashes(buffer);
                buffer = "";
                if (type == '{')
                    res[key] = value;
                else {
                    std::ostringstream convert;
                    convert << k;
                    ++k;
                    res[convert.str()] = value;
                }
                if (chars[i] == '}')
                    break;
            } else {
                buffer += chars[i];
            }
        }
    }
    return res;
}

std::string jsonEncode(const std::map<std::string, std::string> m) {
    std::string res = "{";
    bool first = true;
    std::map<std::string, std::string>::const_iterator itr;
    for (itr = m.begin(); itr != m.end(); ++itr) {
        if (first)
            first = false;
        else
            res += ",";
        res += "\"" + addSlashes((*itr).first) + "\":\"" + addSlashes((*itr).second) + "\"";
    }
    res += "}";
    return res;
}


