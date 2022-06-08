#pragma once
#include "JobObjects.h"
#include "JobObject.h"
#include "AlgoritmCommon.h"
#include "AlgoritmSingle.h"
#include <vector>
using std:: vector;

class BackUp {
private:
    string _namesFiles;
    string _nameFile;
    vector<string> _VnamesFiles;
    vector<string> _VnameFile;
public:
    BackUp(JobObject file, Repository pathRepo, const string& algortim);

    BackUp(JobObjects files, Repository pathRepo);

    string getBackUpListForOneFile(int n);

    string getBackUpListForLotOfFiles(int k);

    BackUp();

};


