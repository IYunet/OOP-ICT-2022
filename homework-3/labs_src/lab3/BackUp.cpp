#include "BackUp.h"
#include <ctime>

BackUp::BackUp(JobObject file, Repository pathRepo, const string& algortim) {
    algortim;
    time_t seconds = time(nullptr);
    _nameFile = file.getOnlyNameFile()+ "_" + to_string(seconds);
    _VnameFile.push_back(_nameFile);
    AlgoritmSingle single(file, pathRepo);
}

BackUp::BackUp(JobObjects files, Repository pathRepo) {
    for (int i = 0; i < files.getListOfFIle().size() ;i++) {
        _namesFiles += files.getListOfFIle()[i].getOnlyNameFile() + "_" ;
    }
    time_t seconds = time(nullptr);
    _namesFiles += to_string(seconds);
    _VnamesFiles.push_back(_namesFiles);
    AlgoritmCommon common(files, pathRepo);
}

string BackUp::getBackUpListForOneFile(int n) {
    return _VnameFile[n];
}

string BackUp::getBackUpListForLotOfFiles(int k) {
    return _VnamesFiles[k];
}

BackUp::BackUp() = default;

