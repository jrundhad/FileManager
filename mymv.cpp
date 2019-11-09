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
  std:: string Name;
  std:: string new_name;
  Name = argv[1];
  new_name = argv[2];
  fileManager file(Name);
  int result= file.renamefile(new_name);
  if (result==0){
    std::cout << "file successfully moved" << '\n';
  } else {
    std::cout << "File could not be moved (check Permissions)" << '\n';
  }
}
