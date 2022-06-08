#pragma once
#include "JobObject.h"

using std::vector;

class JobObjects {
private:
    vector<JobObject> _listOfFiles;
public:

    vector<JobObject> addJobObject(JobObject file);

    vector<JobObject> getListOfFIle();

    JobObject getCorrentFileInListOfFIle(int n);

    std::__wrap_iter<vector<JobObject, std::allocator<JobObject>>::pointer> deleteCorrentFileInListOfFIle(int n);

};


