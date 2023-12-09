//
// Created by arno on 9/12/23.
//
#include "FileSystem.h"

#if defined(_WIN32)
#include <windows.h>
bool createDirectory(const std::string& dirPath) {
    if (CreateDirectory(dirPath.c_str(), NULL) == 0) {
        return false;
    }
    return true;
}
bool directoryExists(const std::string& dirPath) {
    struct stat info;

    if (stat(dirPath.c_str(), &info) != 0) {
        return false;
    } else if (info.st_mode & S_IFDIR) {
        return true;
    } else {
        return false;
    }
}
#elif defined(__unix__)
#include <sys/stat.h>
bool createDirectory(const std::string& dirPath) {
    if (mkdir(dirPath.c_str(), 0777) == -1) {
        return false;
    }
    return true;
}
bool directoryExists(const std::string& dirPath) {
    struct stat info{};

    if (stat(dirPath.c_str(), &info) != 0) {
        return false;
    } else if (info.st_mode & S_IFDIR) {
        return true;
    } else {
        return false;
    }
}
#endif