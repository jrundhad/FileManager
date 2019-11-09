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
  //if user only entered one argument print the files in current dir
  if(argc==1){
    std::string currentdir =".";
    fileManager file = fileManager(currentdir);
    file.expand();
    std::vector<fileManager> kids = file.getchildren();
    for(int i=2 ; i<kids.size() ; i++){
      std::cout << kids[i].getName() << '\n';
    }
  } else if (argc==2){
    //if the user enters only 2 arguments and its not -l print the files in given directory
    std::string Name= argv[1];
    if(Name!= "-l"){
      fileManager file(Name);
      if (file.getType()== "Directory "){
        file.expand();
        std::vector<fileManager> kids = file.getchildren();
        for(int i=2 ; i<kids.size() ; i++){
          std::cout << kids[i].getName() << '\n';
        }
      } else {
        std::cout << "file is not directory" << '\n';
        exit(1);
      }
    } else{
      //print all the files in the current directory and all the information associated with the -l extension
      std::string currentdir =".";
      fileManager file = fileManager(currentdir);
      file.expand();
      std::vector<fileManager> kids = file.getchildren();
      for(int i=2 ; i<kids.size() ; i++){
        std::cout << kids[i].getpermissions() << "\t" << kids[i].getOwner()<< "\t" << kids[i].getgrp() << "\t" << kids[i].getsize() << "\t" << kids[i].getAccessTime() << "\t" << kids[i].getName();
      }
    }
    //if arguments are 3 then print all the files in the given directory and the content assoicated with the -l extension
  } else if (argc==3){
    std::string Name= argv[1];
    std::string argument = argv[2];
    if(argument=="-l"){
      fileManager file = fileManager(Name);
      file.expand();
      std::vector<fileManager> kids = file.getchildren();
      for(int i=2 ; i<kids.size() ; i++){
        std::cout << kids[i].getpermissions() << " " << kids[i].getOwner()<< " " << kids[i].getgrp() << " " << kids[i].getsize() << " " << kids[i].getAccessTime() << " " << kids[i].getName() <<"\n";
      }
    } else {
      std::cout << "incorrect argument" << '\n';
      exit(1);
    }
  }

};
