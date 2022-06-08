#pragma once
#include "Repository.h"
#include "JobObjects.h"
#include <ctime>
#include <filesystem>
namespace fs = std::filesystem;
using std::to_string;

class AlgoritmCommon {
private:
    string _newNameFile, _flag;
    time_t _seconds;
public:
    AlgoritmCommon(JobObjects files, Repository& path);

};


