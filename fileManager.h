#ifndef FILEMANAGER
#define FILEMANAGER
#include <iostream>
#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fcntl.h>
#include <fstream>

class fileManager{
  private:
    int type;
    long size;
    std::string name;
    int UserId;
    struct passwd *Owner;
    int GroupId;
    struct group *grp;
    int Permissions;
    std::string accessTime;
    std::string modTime;
    std::string statTime;
    long blockSize;
    int errnumber;
    std::vector <fileManager*> children;
    struct stat buf;
    std::string perms;

  public:
    fileManager(std::string file_Name);
    ~fileManager();

    std::string getType();
    std::string getName();
    long getsize();
    int getUserId();
    std::string getOwner();
    int getgroupId();
    std::string getgrp();
    std::string getpermissions();
    std::string getAccessTime();
    std::string getmodTime();
    std::string getstatTime();
    long getblockSize();
    int renamefile(std::string new_name);
    int removefile();
    int dump(std::fstream *fileStream);
    int compare(fileManager::f1);
    int geterrnum();
};

#endif
