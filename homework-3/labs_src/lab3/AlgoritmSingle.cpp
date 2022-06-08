#include "AlgoritmSingle.h"
using std::to_string;


AlgoritmSingle::AlgoritmSingle(JobObject file, Repository& path) {
    if (std::filesystem::exists(file.getNameOrPathOfFile())){
        string suff;
        _seconds = time(nullptr);
        suff = "_";
        _newNameFile = path.getPathToRealRepo() + file.getOnlyNameFile() + suff + to_string(_seconds) + ".zip";
        fs:: copy(file.getNameOrPathOfFile(),
                  _newNameFile);
    }
    else{
        _seconds = time(nullptr);
        _copyFile = file;
        _newNameFile = _copyFile.getOnlyNameFile() + "_" + to_string(_seconds) + ".zip";
        path.addNameOfFileToImgRepo(_newNameFile);
        // Store backUpFile(_newNameFile);
    }

}

string AlgoritmSingle::getNewNameFile() {
    return _newNameFile;
}

