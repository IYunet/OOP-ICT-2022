#include "JobObjects.h"


vector<JobObject> JobObjects::addJobObject(JobObject file) {
    _listOfFiles.push_back(file);
    return _listOfFiles;
}

vector<JobObject> JobObjects::getListOfFIle() {
    return _listOfFiles;
}

JobObject JobObjects::getCorrentFileInListOfFIle(int n) {
    return _listOfFiles[n];


}

std::__wrap_iter<vector<JobObject, std::allocator<JobObject>>::pointer> JobObjects::deleteCorrentFileInListOfFIle(int n) {
    return _listOfFiles.erase(_listOfFiles.begin() + n);
}



