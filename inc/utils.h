#ifndef UTILS_H
#define UTILS_H
#include <stdlib.h>
#include <stdbool.h>
bool checkFileType(const char *path, const char *extstr);
void printFileError(long int filesize, const char *path, const char *text);
char *readBinaryFile(const char *path, long int *filesize);
char **readDirFiles(const char *path, size_t *filecount);
char *getFileNameFromPath(const char *path);
void printStringArray(const char *msg, char **array, size_t len);
void sortStringArray(char **array, size_t len);
// meshdata_t *readObjFile(const char *path, meshdata_t *meshdata);
#endif /* UTILS_H */
