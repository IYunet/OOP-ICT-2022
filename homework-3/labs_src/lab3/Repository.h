#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include "JobObject.h"
#include <vector>
using std::to_string;
using std::string;
using std::vector;

class Repository {
private:
    string _path;
    vector<string> _pathIm;
public:
    Repository();

    explicit Repository(string path );

    string getPathToRealRepo();

    vector<string> getPathToImgRepo();

    string getCorrentFileInImgRepo(int n);

    void addNameOfFileToImgRepo(const string& nameFile);

};



