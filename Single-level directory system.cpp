#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 20
#define MAX_DIRECTORY_NAME_LENGTH 20

struct file {
    char filename[MAX_FILENAME_LENGTH];
};

struct directory {
    char dirname[MAX_DIRECTORY_NAME_LENGTH];
    struct file files[MAX_FILES];
    int num_files;
};

void create_directory(struct directory *dir, char *name) {
    strcpy(dir->dirname, name);
    dir->num_files = 0;
}

void add_file(struct directory *dir, char *filename) {
    if (dir->num_files < MAX_FILES) {
        strcpy(dir->files[dir->num_files].filename, filename);
        dir->num_files++;
        printf("File %s added to directory %s\n", filename, dir->dirname);
    } else {
        printf("Error: Maximum number of files reached for directory %s\n", dir->dirname);
    }
}

int main() {
    struct directory cse_dir;
    create_directory(&cse_dir, "CSE");

    add_file(&cse_dir, "A");
    add_file(&cse_dir, "B");
    add_file(&cse_dir, "C");

    return 0;
}
