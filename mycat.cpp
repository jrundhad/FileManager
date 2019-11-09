/*
Author: Jeet Undhad

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
#include <fstream>
#include "fileManager.h"

int main(int argc, char *argv[]){
  //create output stream
  std::ofstream output;
  // for all arguments if its a real text file  dump the content to console
  for(int i=1; i<argc;i++){
    fileManager file = fileManager(argv[i]);
    if (file.geterrnum()!=0){
      std:: cerr<< "file not found" << std::endl;
      exit(1);
    }
    if(file.getType()== "text file"){
      file.dump(output);
      fileManager new_file = fileManager("new"+file.getName());
      //remove the new file created
      new_file.removefile();
    }
  }
  std::cout << '\n';

}
