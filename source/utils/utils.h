#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <unistd.h>
#include <vector>
#include <exception>

#include <dirent.h>
#include <sys/stat.h>

#include "json/json-forwards.h"
#include "json/json.h"

using namespace std;
using namespace Json;

enum TASKSTATUS {
    TASKINIT,
    TASKRUNNING,
    TASKCOMPELETE,
    TASKERROR,
    ARGERROR
};

enum FileMode {
    EXISTS,
    WRITEABLE,
    READABLE,
    RWABLE,
    NOTEXISTS
};

typedef struct _ResultStatus {
    int stauts;
    FileMode mode;
    string desc;
}ResultStatus;

typedef struct _TaskPackStruct {
    void* input;
    void* output;
}TaskPackStruct;

void checkFileInfo(string filePath, ResultStatus& status);
bool isExistsFile(string filePath);

void read_config_Json(string fileName, map<string, string>& argvMap);
string getPGConfInfo(const map<string, string>& argvMap);
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);

bool createFolder(string path);
bool checkFilePath(string paths);

#endif // UTILS_HPP

