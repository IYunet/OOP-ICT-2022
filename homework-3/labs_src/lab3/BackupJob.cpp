#include "BackupJob.h"

#include <utility>
using std::vector;

BackupJob::BackupJob(string pathToRepo) {
    Repository path(std::move(pathToRepo));
    _path = path;
}

void BackupJob::addFile(string nameOrPAthOfFile) {
    JobObject _file(std::move(nameOrPAthOfFile));
    _files.addJobObject(_file);
}

void BackupJob::algoritm(const string& mode) {
    if (mode == "single") {
        for (int i = 0; i < _files.getListOfFIle().size(); i++) {
            JobObject file;
            file = _files.getListOfFIle()[i];
            _newNamePoint += file.getOnlyNameFile() + "_";
            BackUp back1(file, _path, mode);
            _back = back1;
            _backUps.push_back(_back);
        }
        time_t seconds = time(nullptr);
        _restorePoints.push_back(_newNamePoint + to_string(seconds));
        _newNamePoint = "";
    }
    if (mode == "common"){
    BackUp back1(_files,_path );
    _back = back1;
    _backUps.push_back(_back);
}
}

void BackupJob::deleteFile(int n) {
    _files.deleteCorrentFileInListOfFIle(n);
}

string BackupJob::getInfoOfPointForCommonAlg(int k) {
     return _backUps[k].getBackUpListForLotOfFiles(0);
}

string BackupJob::getInfoOfPointForSingleAlg(int k) {
    return _backUps[k].getBackUpListForOneFile(0);
}

string BackupJob::getRestorePoint(int n) {
    return _restorePoints[n];
}






