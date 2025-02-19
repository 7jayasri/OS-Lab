   // 1) Write programs using the following UNIX operating system calls for opendir and readdir and closedir
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main() {
    char buff[100];
    DIR *dirp;
    struct dirent *dptr;  
    printf("\n\nEnter directory name: ");
    scanf("%s", buff);
    
    dirp = opendir(buff);
    if (dirp == NULL) {
        printf("The given directory does not exist.\n");
        exit(1);
    }

    
    printf("Contents of directory %s:\n", buff);
    while ((dptr = readdir(dirp)) != NULL) {
        printf("%s\n", dptr->d_name);
    }
  
    closedir(dirp);
    return 0;
}
