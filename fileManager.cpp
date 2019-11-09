#include "fileManager.h"




  fileManager::fileManager(std::string file_Name){
      this->name = file_Name;
      if(stat(file_Name.c_str(), &buf) != -1){
        this->type = buf.st_mode;
        this->size = buf.st_size;
        this->UserId = buf.st_uid;
        this->Owner = getpwuid(UserId);
        this->GroupId = buf.st_gid;
        this->grp = getgrgid(GroupId);
        this->Permissions = buf.st_mode;
        this->accessTime = ctime(&buf.st_atime);
        this->modTime = ctime(&buf.st_mtime);
        this->statTime = ctime(&buf.st_ctime);
        this->blockSize = buf.st_blksize;
        this->errnumber = errno;
      } else {
        this->errnumber = errno;
        //fileManager()
        cerr<< "FILE NOT FOUND"
        ~fileManager()
        exit(1);
      }

    }

    fileManager::~fileManager(){
    }

    std::string fileManager::getType(){
      if (S_ISREG(buf.st_mode)) {
          return "text file";
      }
      if (S_ISDIR(buf.st_mode)){
          return "Directory ";
      }
      if (S_ISCHR(buf.st_mode)){
        return " character Device ";
      }
      if (S_ISBLK(buf.st_mode)){
        return "block Device";
      }
      if (S_ISFIFO(buf.st_mode)){
        return "FIFO ";
      }
      if (S_ISLNK(buf.st_mode)){
        return "Symbolic Link";
      }
      if (S_ISSOCK(buf.st_mode)){
        return "Socket";
      }
      else{
        return 0;
      }
    }

    std::string fileManager::getName(){
      return name;
    }

    long fileManager::getsize(){
      return size;
    }

    int fileManager::getUserId(){
      return UserId;
    }

    std::string fileManager::getOwner(){
      return Owner->pw_name;
    }

    int fileManager::getgroupId(){
      return GroupId;
    }

    std::string fileManager::getgrp(){
      return grp->gr_name;
    }

    std::string fileManager::getpermissions(){
      perms="";
      if ((buf.st_mode) & S_IRUSR) {
          perms= perms + "r";
      }
      else {
        perms= perms + "-";
      }

      if ((buf.st_mode) & S_IWUSR) {
          perms= perms + "w";
      }
      else {
        perms= perms + "-";
      }

      if ((buf.st_mode) & S_IXUSR) {
          perms= perms + "x";
      }
      else {
        perms= perms + "-";
      }

      if ((buf.st_mode) & S_IRGRP) {
          perms= perms + " r";
      }
      else {
        perms = perms + " -";
      }

      if ((buf.st_mode) & S_IWGRP) {
          perms= perms + "w";
      }
      else {
        perms = perms + "-";
      }

      if ((buf.st_mode) & S_IXGRP) {
          perms= perms + "x";
      }
      else {
        perms = perms + "-";
      }

      if ((buf.st_mode) & S_IROTH) {
          perms= perms + " r";
      }
      else {
        perms = perms + " -";
      }

      if ((buf.st_mode) & S_IWOTH) {
          perms= perms + "w";
      }
      else {
        perms = perms + "-";
      }

      if ((buf.st_mode) & S_IXOTH) {
          perms= perms + "x";
      }
      else {
        perms = perms + "-";
      }
      return perms;
    }

    std::string fileManager::getAccessTime(){
      return accessTime;
    }

    std::string fileManager::getmodTime(){
      return modTime;
    }

    std::string fileManager::getstatTime(){
      return statTime;
    }

    long fileManager::getblockSize(){
      return blockSize;
    }

    int fileManager::renamefile(std::string new_name){
      int result = rename( name.c_str(), new_name.c_str());
      if ( result == 0 ){
        name=new_name;
        return 0;
      }
      else {
        errnumber=errno;
        return -1;
      }
    }

    int fileManager::removefile(){
      int result = unlink(name.c_str());
      if ( result == 0 )
        return 0;
      else{
        errnumber=errno;
        return -1;
      }
    }

    int fileManager::dump(std::fstream *fileStream){
      char arr[blockSize];
      std::fstream file;
      file.open(name.c_str());
      if (file.fail()){
        return -1;
      }
      file.getline(arr,blockSize);
      fileStream->write(arr,blockSize);
      return 0;
    }

    int fileManager::geterrnum(){
      return errnumber; 
    }


    int fileManager::compare(fileManager::f1){
      return 0
    }
