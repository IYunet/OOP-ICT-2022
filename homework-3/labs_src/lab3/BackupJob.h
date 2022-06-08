#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include "JobObjects.h"
#include "JobObject.h"
#include "AlgoritmSingle.h"
#include "BackUp.h"
#include "Repository.h"

using std::string;

class BackupJob {
private:
    Repository _path;
    JobObjects _files;
    vector<string> _restorePoints;
    vector<BackUp> _backUps;
    BackUp _back;
    string _newNamePoint;

public:
    explicit BackupJob(string pathToRepo);

    void addFile(string nameOrPAthOfFile);

    void algoritm(const string& mode);

    void deleteFile(int n);

    string getInfoOfPointForCommonAlg(int k);

    string getInfoOfPointForSingleAlg(int k);

    string getRestorePoint(int n);

};
