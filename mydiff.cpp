/*
Author: Jeet Undhad
student#: 250981608
date: Oct 3 2019
*/
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

int main(int argc, char *argv[2]){
    //initializes variables with arguments and creates file manager object
  if(argc!=3){
    std::cout << "wrong number of arguments" << '\n';
    exit(1);
  }
  //initializes variables with arguments and creates file manager object
  std::string Name;
  std::string new_file;
  Name = argv[1];
  new_file = argv[2];
  fileManager file(Name);
  if (file.geterrnum()!=0){
    std:: cerr<< "file not found" << std::endl;
    exit(1);
  }
  fileManager file2(new_file);
  if (file2.geterrnum()!=0){
    std:: cerr<< "file not found" << std::endl;
    exit(1);
  }
  //compare the two files and let user know if operation went succesfull
  if(file.compare(file2)==0){
    std::cout << "files are the same" << '\n';
  } else {
    std::cout << "files are different" << '\n';
  }
}
