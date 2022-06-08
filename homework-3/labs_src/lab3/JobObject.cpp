#include "JobObject.h"
#include <vector>
using std::vector;

JobObject::JobObject() {
    _pathToFileOrNameFile = "untitled";
    _file.push_back(_pathToFileOrNameFile);
}

JobObject::JobObject(string pathToFileOrNameFile) {
    _pathToFileOrNameFile = pathToFileOrNameFile;
    _file.push_back(_pathToFileOrNameFile);

}

vector<string> JobObject::getFile() const {
    return _file;
}

string JobObject::getNameOrPathOfFile() const {
    return _file[0];
}

string JobObject::getOnlyNameFile() {
    string pathOrName = _file[0];
    const char* delims = "/";
    std::string::size_type pos;
    pos = pathOrName.find_last_of(delims);
    pathOrName.erase(0, pos+1);

    const char* delims1 = ".";
    std::string::size_type pos1;
    std::string::size_type pos2;
    pos1 = pathOrName.find_first_of(delims1);
    pos2 = pathOrName.length();
    pathOrName.erase(pos1, pos2);
    return pathOrName;
}

JobObject::~JobObject() = default;







