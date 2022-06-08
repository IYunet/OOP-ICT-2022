#include "AlgoritmCommon.h"

AlgoritmCommon::AlgoritmCommon(JobObjects files, Repository& path) {
    _newNameFile = path.getPathToRealRepo();
    for (int i = 0; i < files.getListOfFIle().size(); i++){

        if (std::filesystem::exists(files.getListOfFIle()[i].getNameOrPathOfFile()))
    {
        string suff;
        _seconds = time(nullptr);
        suff = "_";
        _newNameFile += files.getListOfFIle()[i].getOnlyNameFile() + suff;
        _flag = "real";
    }

}
    if (_flag == "real"){
    _newNameFile += to_string(_seconds) + ".zip";
    fs:: copy(files.getListOfFIle()[0].getNameOrPathOfFile(),
              _newNameFile);}
    else {
        _newNameFile = ""; //path.getPathToImgRepo()[0];
        for (int i = 0; i < files.getListOfFIle().size(); i++) {

            _newNameFile += files.getListOfFIle()[i].getOnlyNameFile() + "_";
        }
        _seconds = time(nullptr);
        _newNameFile += to_string(_seconds) + ".zip";
        path.addNameOfFileToImgRepo(_newNameFile);
    }
}
