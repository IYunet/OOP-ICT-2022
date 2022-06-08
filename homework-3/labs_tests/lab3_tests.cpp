#include <gtest/gtest.h>
#include "lab3/JobObject.h"
#include "lab3/BackupJob.h"
#include <unistd.h>

using namespace std;

TEST(CreateBackups, TwoRestorePointsAndThreeStoragesCreated) {
    BackupJob job1("path_img");
    job1.addFile("fileA.txt");
    job1.addFile("fileB.txt");
    job1.addFile("fileC.txt");
    job1.algoritm("single");
    time_t seconds1 = time(nullptr);
    sleep(1);
    time_t seconds2 = time(nullptr);
    job1.deleteFile(2);
    job1.algoritm("single");
// проверка, что создан забэкапленный файл: джоба была запущена два раза,
// алгоритм раздельного хранения, после первого запуска джобу был удален один файл
// в итоге должно быть 5 забэкалпенных файлов
    ASSERT_EQ(job1.getInfoOfPointForSingleAlg(0), "fileA_" + to_string(seconds1));
    ASSERT_EQ(job1.getInfoOfPointForSingleAlg(1), "fileB_" + to_string(seconds1));
    ASSERT_EQ(job1.getInfoOfPointForSingleAlg(2), "fileC_" + to_string(seconds1));
    ASSERT_EQ(job1.getInfoOfPointForSingleAlg(3), "fileA_" + to_string(seconds2));
    ASSERT_EQ(job1.getInfoOfPointForSingleAlg(4), "fileB_" + to_string(seconds2));

// проверка на создание рестор поинтов (две штуки)
    ASSERT_EQ(job1.getRestorePoint(0), "fileA_fileB_fileC_" + to_string(seconds1));
    ASSERT_EQ(job1.getRestorePoint(1), "fileA_fileB_" + to_string(seconds2));
}


// Для реальной фалйовой системы
//TEST(CreateBuckupJob, NewNameFiles){
//    BackupJob job1("/Users/yunet/Documents/test_file/ttttt/");
//    job1.addFile("/Users/yunet/Documents/test_file/fileA.txt");
//    job1.addFile("/Users/yunet/Documents/test_file/fileB.txt");
//    job1.addFile("/Users/yunet/Documents/test_file/fileC.txt");
//    job1.algoritm("common");
//    sleep(1);
//    job1.deleteFile(1);
//    job1.algoritm("common");
//
//}