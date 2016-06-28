#include "utils.h"

void checkFileInfo(string filePath, ResultStatus& status) {
    if(access(filePath.c_str(), 0) == 0) {

        status.stauts = 0;
        status.mode = EXISTS;
        status.desc = "EXISTS";

        if(access(filePath.c_str(), 2) == 0) {
            status.stauts = 0;
            status.mode = WRITEABLE;
            status.desc = "WRITEABLE";
        }

        if(access(filePath.c_str(), 4) == 0) {
            status.stauts = 0;
            status.mode = READABLE;
            status.desc = "READABLE";
        }

        if(access(filePath.c_str(), 6) == 0) {
            status.stauts = 0;
            status.mode = RWABLE;
            status.desc = "RWABLE";
        }
    } else {
        status.stauts = -1;
        status.mode = NOTEXISTS;
        status.desc = "NOTEXISTS";
    }
}

bool isExistsFile(string filePath) {
    if(access(filePath.c_str(), 0) == 0) {
        return true;
    }
    return false;
}

void read_config_Json(string fileName, map<string, string> &argvMap, map<string, vector<string>> &argvMap2) {
    Json::Reader reader;
    Json::Value root;
    ifstream in;
    in.open(fileName.c_str(), std::ios_base::binary);
    if(in.is_open() == false) {
        throw runtime_error("Read Configure Json File Error !");
        cerr << "Read Configure Json File Error !" << endl;
    }
    bool flag = reader.parse(in, root, false);
    if(flag == false) {
        throw runtime_error("Configure Json File Format Error !");
        cerr << "Configure Json File Format Error !" << endl;
    }
    argvMap["ROOTDIR"] = root.get("ROOTDIR", "NULL").asString();
    argvMap["LOGPATH"] = root.get("LOGPATH", "NULL").asString();

    if(root.isMember("SAMPLES") == true) {
        argvMap["SAMPLES_ISUSE"] = root["SAMPLES"].get("ISUSE", "FALSE").asString();
        if(argvMap["SAMPLES_ISUSE"] == "TRUE") {
            argvMap["CONTROLDIR"] = root["SAMPLES"].get("CONTROLDIR", "NULL").asString();
            argvMap["NUMSDIR"] = root["SAMPLES"].get("NUMSDIR", "NULL").asString();

            Json::Value value_array_control = root["SAMPLES"]["CONTROLFLAGS"];
            vector<string> tmp1;
            for(int i=0;i<value_array_control.size();++i) {
                //cout << value_array_control[i] << endl;
                tmp1.push_back(value_array_control[i].asString());
            }
            argvMap2["CONTROLFLAGS"] = tmp1;

            Json::Value value_array_nums = root["SAMPLES"]["NUMFLAGS"];
            vector<string> tmp2;
            for(int i=0;i<value_array_nums.size();++i) {
                //cout << value_array_nums[i] << endl;
                tmp2.push_back(value_array_nums[i].asString());
            }
            argvMap2["NUMFLAGS"] = tmp2;
        }
    }

    if(root.isMember("FEATURES") == true) {
        argvMap["FEATURES_ISUSE"] = root["FEATURES"].get("ISUSE", "FALSE").asString();
        if(argvMap["FEATURES_ISUSE"] == "TRUE") {
            argvMap["GESTUREFILE"] = root["FEATURES"].get("GESTUREFILE", "NULL").asString();
            argvMap["HANDFILE"] = root["FEATURES"].get("HANDFILE", "NULL").asString();

        }
    }

    for(map<string, string>::iterator it=argvMap.begin(); it!=argvMap.end(); it++) {
        if(it->second == "NULL") {
            cerr << it->first << " is " << it->second << endl;
            throw runtime_error("Configure Json File Parameter Error !");
        }
    }
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

bool createFolder(string path) {
    if(access(path.c_str(), 0) != 0) {
        if (!mkdir(path.c_str(), 0775)) {
            return true;
        } else {
            cerr << "createFolder " << path << "failed" << endl;
        }
    }
    return true;
}

bool checkFilePath(string paths) {
    string tmp;
    size_t end_pos = paths.rfind('/');
    tmp = paths.substr(0, end_pos);
    paths = tmp;
    size_t pos = paths.find('/');

    while(pos = paths.find("/", pos+1), pos != string::npos) {
        tmp = (paths.substr(0, pos));
        if(!createFolder(tmp)) {
            return false;
        }
    }
    if(!createFolder(paths)) {
        return false;
    }
    return true;
}
