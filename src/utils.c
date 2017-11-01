#include "utils.h"
#include "meshdata.h"
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <alloca.h>

void sortStringArray(char **array, size_t len)
{
    // insertion sort
    size_t i, j, k;
    for (i = 1; i < len; ++i) {
        for (j = i, k = i - 1; j > 0 && strcmp(array[k], array[k]) > 0; j--, k--) {
            char *tmp = array[k];
            array[k] = array[j];
            array[j] = tmp;
        }
    }
}

void printStringArray(const char *msg, char **array, size_t len)
{
    if (msg) printf("\n%s\n", msg);
    size_t i;
    for (i = 0; i < len; ++i)
        printf("%lu: %s\n", i, array[i]);
    printf("\n");
}

char *getFileNameFromPath(const char *path)
{
    size_t path_len = strlen(path) + 1;
    size_t buffer_len = 0;
    size_t i = path_len;
    char c = 'a';
    while (c != '/' && i != 0) {
        c = path[i--];
        buffer_len++;
    }
    char *buffer = malloc(sizeof(char) * buffer_len);
    memcpy(buffer, path + path_len - buffer_len + 2, buffer_len);
    for (i = 0; i < buffer_len; ++i)
        if (buffer[i] == '.')
            buffer[i] = '\0';
    return buffer;
}

bool checkFileType(const char *path, const char *extstr)
{
    size_t extlen = strlen(extstr) + 1;
    char *buf = alloca(extlen * sizeof(char) + 1);
    memcpy(buf, path + strlen(path) + 1 - extlen, extlen * sizeof(char));
    return (strcmp(buf, extstr) == 0);
}


void printFileError(long int filesize, const char *path, const char *text)
{
    fprintf(stderr, "%lu bytes. Filepath: %s\ntext:\n%s\n", filesize, path, text);
}

char **readDirFiles(const char *path, size_t *filecount)
{
    struct dirent *ent;
    DIR *dir;

    dir = opendir(path);
    if (!dir) {
        fprintf(stderr, "Could not open directory %s\n", path);
        return NULL;
    }

    size_t num_files = 0;
    long tell = telldir(dir);

    while ((ent = readdir(dir)) != NULL) {
        num_files++;
    }

    size_t pathlen = strlen(path);
    seekdir(dir, tell);
    num_files -= 2;
    char **paths = malloc(sizeof(char *) * num_files);
    size_t cur = 0;
    while ((ent = readdir(dir)) != NULL) {
        if ((strcmp("..", ent->d_name) == 0) || (strcmp(".", ent->d_name) == 0))
            continue;
        size_t len = strlen(ent->d_name);
        paths[cur] = malloc(sizeof(char) * len * pathlen + 2);
        strcpy(paths[cur], path);
        strcat(paths[cur], "/");
        strcat(paths[cur], ent->d_name);
        cur++;
    }

    closedir(dir);

    *filecount = num_files;
    return paths;
}

char *readBinaryFile(const char *path, long int *filesize)
{
    int fd;
    int error;
    long int buffersize;
    long int readlen;
    struct stat stats;
    char *buffer;

    error = stat(path, &stats);
    if (error) {
        fprintf(stderr, "Error getting file stats: %s\n", strerror(errno));
        return NULL;
    }

    fd = open(path, O_RDONLY);

    if (fd == -1) {
        fprintf(stderr, "Unable to open file %s: %s\n", path, strerror(errno));
        return NULL;
    }

    buffersize = stats.st_size;
    *filesize = buffersize;

    buffer = malloc((size_t)buffersize + 1);
    assert(buffer);

    readlen = read(fd, buffer, (size_t)buffersize);

    if (readlen !=  buffersize) {
        fprintf(stderr, "read error: %s\n", strerror(errno));
        close(fd);
        free(buffer);
        return NULL;
    }

    buffer[buffersize] = '\0';

    close(fd);

    return buffer;
}
