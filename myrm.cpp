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
  int result = file.removefile();
  if (result==0){
    std::cout << "file successfully removed" << '\n';
  } else {
    std::cout << "File could not be removed (check Permissions)" << '\n';
  }
}
