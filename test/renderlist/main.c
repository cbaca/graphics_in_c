#include "renderlist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    RenderList *rl0 = newRenderList("alist");
    RenderList *rl1 = newRenderList("blist");
    char command[256];
    char arg0[256];
    char arg1[256];
    size_t i = 0;
    int c = 1;
    while(c != EOF) {
        i = 0;
        c = getchar();
        while (c != ' ' && c != '\n') {
            command[i++] = (char)c;
            c = getchar();
        }
        command[i++] = '\0';
        printf("command: %s\n", command);

        i = 0;

        if (strcmp(command, "push") == 0) {
            c = getchar();
            while (c != ' ') {
                arg0[i++] = (char)c;
                c = getchar();
            }
            arg0[i++] = '\0';
            i = 0;
            c = getchar();
            while (c != '\n') {
                arg1[i++] = (char)c;
                c = getchar();
            }
            arg1[i++] = '\0';

            if (strcmp(arg0, "alist") == 0)
                pushRenderList(rl0, arg1);
            else
                pushRenderList(rl1, arg1);
        }

        else if (strcmp(command, "pop") == 0) {
            c = getchar();
            while (c != '\n') {
                arg0[i++] = (char)c;
                c = getchar();
            }
            arg0[i++] = '\0';

            char *buf = NULL;
            if (strcmp(arg0, "alist") == 0)
                buf = popRenderList(rl0);
            else
                buf = popRenderList(rl1);
            printf("Popped %s\n", buf != NULL ? buf : "nothing");
            if (buf)
                free(buf);

        } else if (strcmp(command, "print") == 0) {
            goto printlist;

        } else if (strcmp(command, "remove") == 0) {
            c = getchar();
            while (c != ' ') {
                arg0[i++] = (char)c;
                c = getchar();
            }
            arg0[i++] = '\0';
            i = 0;
            c = getchar();
            while (c != '\n') {
                arg1[i++] = (char)c;
                c = getchar();
            }
            arg1[i++] = '\0';

            ObjNode *tmp = NULL;
            if (strcmp(arg0, "alist") == 0)
                tmp = removeSearch(rl0, arg1);
            else
                tmp = removeSearch(rl1, arg1);
            if (tmp) {
                if (strcmp(tmp->name, arg1) == 0)
                    printf("Match. Removing\n");
                else
                    printf("err\n");
            } else {
                printf("no match. Cannot remove\n");
            }

            if (tmp) {
                free(tmp->name);
                free(tmp);
            }

        } else if (strcmp(command, "search") == 0) {
            c = getchar();
            while (c != ' ') {
                arg0[i++] = (char)c;
                c = getchar();
            }
            arg0[i++] = '\0';
            i = 0;
            c = getchar();
            while (c != '\n') {
                arg1[i++] = (char)c;
                c = getchar();
            }
            arg1[i++] = '\0';

            ObjNode *tmp = NULL;
            if (strcmp(arg0, "alist") == 0)
                tmp = searchList(rl0, arg1);
            else
                tmp = searchList(rl1, arg1);
            if (tmp) {
                if (strcmp(tmp->name, arg1) == 0)
                    printf("Match!\n");
                else
                    printf("err\n");
            } else {
                printf("no match\n");
            }

        } else if (strcmp(command, "compare") == 0) {
            c = getchar();
            while (c != '\n') {
                arg0[i++] = (char)c;
                c = getchar();
            }
            arg0[i++] = '\0';

            if (strcmp(arg0, "alist") == 0)

                compareAndUpdateList(rl0, rl1);

            else

                compareAndUpdateList(rl1, rl0);

        } else if (strcmp(command, "trap") == 0) {
            c = getchar();
            while (c != '\n') {
                arg0[i++] = (char)c;
                c = getchar();
            }
            arg0[i++] = '\0';

            if (strcmp(arg0, "alist") == 0) {
                ObjNode *it = rl0->root;
                while (it) {
                    it->name[0] = 'b';
                    it->renderMode = (RenderMode)it->name[0];
                    it = it->next;
                }
            } else {
                ObjNode *it = rl1->root;
                while (it) {
                    it->name[0] = 'a';
                    it->renderMode = (RenderMode)it->name[0];
                    it = it->next;
                }
            }

        } else if (strcmp(command, "q") == 0) {
            c = EOF;
            break;
        }






        printlist:
        printList(rl0);
        printList(rl1);
        printf("\n");
    }
    destroyRenderList(rl0);
    destroyRenderList(rl1);
    return 0;
}
