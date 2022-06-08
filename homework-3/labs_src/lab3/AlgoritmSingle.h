#pragma once
#include "JobObject.h"
#include <ctime>
#include <filesystem>
#include "Repository.h"
namespace fs = std::filesystem;


class AlgoritmSingle {
private:
    JobObject _copyFile;
    string _newNameFile;
    time_t _seconds;
public:
    AlgoritmSingle(JobObject file, Repository& path);

    string getNewNameFile();

};

