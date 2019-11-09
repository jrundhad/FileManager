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
  std::string name;
  std::fstream *new_file;
  name = argv[1];
  fileManager file(name);
  new_file = &argv[2].c_str();
  int result = file.dump(new_file);
  
}
