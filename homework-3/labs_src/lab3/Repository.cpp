#include "Repository.h"

Repository::Repository(string path) {
    if (std::filesystem::exists(path)){
        _path = path;
    }
    else {
        _pathIm.push_back(path);
    }
}

string Repository::getPathToRealRepo() {
    return _path;
}

vector<string> Repository::getPathToImgRepo() {
    return _pathIm;
}

string Repository::getCorrentFileInImgRepo(int n) {
    return _pathIm[n];
}

void Repository::addNameOfFileToImgRepo(const string& nameFile) {
    _pathIm.push_back(nameFile);

}

Repository::Repository() = default;
