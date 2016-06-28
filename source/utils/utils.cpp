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

void read_config_Json(string fileName, map<string, string> &argvMap) {
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
    argvMap["SERVERIP"] = root.get("SERVERIP", "127.0.0.1").asString();
    argvMap["PORT"] = root.get("PORT", "9999").asString();
    argvMap["SERIALIZETIME"] = root.get("SERIALIZETIME", "3600").asString();
    argvMap["LOGPATH"] = root.get("LOGPATH", "NULL").asString();

    if(root.isMember("FUSION") == true) {
        argvMap["FUSIONISUSE"] = root["FUSION"].get("ISUSE", "FALSE").asString();
        argvMap["FUSIONIDENTITY"] = root["FUSION"].get("FUSIONIDENTITY", "NULL").asString();
        argvMap["FUSIONSerializePath"] = root["FUSION"].get("FUSIONSerializePath", "NULL").asString();
        argvMap["FUSIONSerializePathBak"] = root["FUSION"].get("FUSIONSerializePathBak", "NULL").asString();
    }

    if(root.isMember("RETRIEVE") == true) {
        argvMap["RETRIEVEISUSE"] = root["RETRIEVE"].get("ISUSE", "FALSE").asString();
        argvMap["RETRIEVEIDENTITY"] = root["RETRIEVE"].get("RETRIEVEIDENTITY", "NULL").asString();
        argvMap["RETRIEVEPG_NAME"] = root["RETRIEVE"].get("RETRIEVEPG_NAME", "NULL").asString();

        argvMap["RETRIEVEPG_HOST"] = root["RETRIEVE"].get("RETRIEVEPG_HOST", "NULL").asString();
        argvMap["RETRIEVEPG_PORT"] = root["RETRIEVE"].get("RETRIEVEPG_PORT", "NULL").asString();
        argvMap["RETRIEVEPG_USER"] = root["RETRIEVE"].get("RETRIEVEPG_USER", "NULL").asString();
        argvMap["RETRIEVEPG_PASSWD"] = root["RETRIEVE"].get("RETRIEVEPG_PASSWD", "NULL").asString();

        argvMap["RETRIEVEREDIS_HOST"] = root["RETRIEVE"].get("RETRIEVEREDIS_HOST", "NULL").asString();
        argvMap["RETRIEVEREDIS_PORT"] = root["RETRIEVE"].get("RETRIEVEREDIS_PORT", "NULL").asString();
        argvMap["RETRIEVEREDIS_PASSWD"] = root["RETRIEVE"].get("RETRIEVEREDIS_PASSWD", "NULL").asString();

        argvMap["RETRIEVESerializePath"] = root["RETRIEVE"].get("RETRIEVESerializePath", "NULL").asString();
        argvMap["RETRIEVESerializePathBak"] = root["RETRIEVE"].get("RETRIEVESerializePathBak", "NULL").asString();
       
        argvMap["RETRIEVESPARSITY"] = root["RETRIEVE"].get("RETRIEVESPARSITY", "11").asString();
        argvMap["RETRIEVEMINRESIDUAL"] = root["RETRIEVE"].get("RETRIEVEMINRESIDUAL", "1").asString();
    }

    if(root.isMember("QUALITY") == true) {
        argvMap["QUALITYISUSE"] = root["QUALITY"].get("ISUSE", "FALSE").asString();
        argvMap["QUALITYIDENTITY"] = root["QUALITY"].get("QUALITYIDENTITY", "NULL").asString();
        argvMap["QUALTYSerializePath"] = root["QUALITY"].get("QUALTYSerializePath", "NULL").asString();
        argvMap["QUALTYSerializePathBak"] = root["QUALITY"].get("QUALTYSerializePathBak", "NULL").asString();
    }

    for(map<string, string>::iterator it=argvMap.begin(); it!=argvMap.end(); it++) {
        if(it->second == "NULL") {
            cerr << it->first << " is " << it->second << endl;
            throw runtime_error("Configure Json File Parameter Error !");
        }
    }
}

string getPGConfInfo(const map<string, string> &argvMap) {
    string str = "";
    str = "dbname=" + argvMap.at("RETRIEVEPG_NAME") + " user=" + argvMap.at("RETRIEVEPG_USER") + " password=" + argvMap.at("RETRIEVEPG_PASSWD") + " host=" + argvMap.at("RETRIEVEPG_HOST") + " port=" + argvMap.at("RETRIEVEPG_PORT");
    return str;
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