#ifndef __UTIL__
#define __UTIL__

#include <string>

namespace umbrella {
    // Replace
    void replacePattern(std::string & str, std::string from , std::string to) {
        for (size_t i = 0; i < str.length() - from.length() + 1; i++) {
            if (str.compare(i, from.length(), from) == 0) {
                str.replace(i, from.length(), "");
                str.insert(i, to);
                i += to.length() - 1;
            }
        }
    }
}

#endif
