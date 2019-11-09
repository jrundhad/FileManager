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
#include "fileManager.h"

int main(int argc, char *argv[1]){
  std:: string Name;
  Name= argv[1];
  fileManager file(Name);
  std::cout<< "error: " << file.errnumber();
  if(file.geterrnum()==-1){
    exit(1);
  }
  std::cout<< "file is: " << file.getName();
  std::cout<< "\n";
  std::cout << "Type: " << file.getType() ;
  std::cout << "\n" ;
  std::cout << "Size: " << file.getsize() ;
  std::cout <<" bytes\n";
  std::cout << "UserId: " << file.getUserId();
  std::cout << "\n";
  std::cout << "Owner: " << file.getOwner();
  std::cout << "\n";
  std::cout << "GroupId: " << file.getgroupId();
  std::cout << "\n";
  std::cout << "group: " << file.getgrp();
  std::cout << "\n";
  std::cout << "Permissions: " << file.getpermissions();
  std::cout << "\n";
  std::cout << "Access Time: " << file.getAccessTime();
  std::cout << "Modification Time: " << file.getmodTime();
  std::cout << "Status Change Time: " << file.getstatTime();
  std::cout << "Block Size: " << file.getblockSize();
  std::cout << "\n";

}
