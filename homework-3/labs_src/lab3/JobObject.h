#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;

class JobObject {
private:
    string _pathToFileOrNameFile;
    vector<string> _file;
public:

    JobObject();

    explicit JobObject(string pathToFileOrNameFile);

    [[nodiscard]] vector<string> getFile() const;

    [[nodiscard]] string getNameOrPathOfFile() const;

    string getOnlyNameFile();

    virtual ~JobObject();
};

