#include "renderlist.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

static void _freeNodes(ObjNode *on);
void _printList(ObjNode *on);

RenderList *newRenderList(const char *name)
{
    RenderList *rl = malloc(sizeof(RenderList));
    strcpy(rl->name, name);
    rl->root = NULL;
    rl->num_nodes = 0;
    rl->renderMode = (int32_t)name[0];
    return rl;
}

void destroyRenderList(RenderList *rl)
{
    _freeNodes(rl->root);
    free(rl);
}

void pushRenderList(RenderList *rl, const char *name)
{
    ObjNode *on = malloc(sizeof(ObjNode));
    on->name = malloc(sizeof(char) * 100);
    strcpy(on->name, name);
    on->renderMode = (RenderMode)on->name[0];
    rl->num_nodes++;
    if (rl->root)
        rl->root->prev = on;
    on->next = rl->root;
    rl->root = on;
    rl->root->prev = NULL;
}

char *popRenderList(RenderList *rl)
{
    if (!rl->root) return NULL;

    char *ret = rl->root->name;
    ObjNode *next = rl->root->next;
    free(rl->root);
    rl->root = next;
    --rl->num_nodes;
    return ret;
}

void pushObjNode(RenderList *rl, ObjNode *on)
{
    if (!on) return;
    rl->num_nodes++;
    if (rl->root)
        rl->root->prev = on;
    on->next = rl->root;
    rl->root = on;
    rl->root->prev = NULL;
}

ObjNode *popObjNode(RenderList *rl)
{
    if (!rl->root) return NULL;
    ObjNode *ret = rl->root;
    rl->root = rl->root->next;
    if (rl->root)
        rl->root->prev = NULL;
    ret->next = NULL;
    rl->num_nodes--;
    return ret;
}

ObjNode *removeSearch(RenderList *rl, const char *tar)
{
    ObjNode *target = searchList(rl, tar);
    if (!target)
        return NULL;
    if (target->prev == NULL) {
        if (target->next) {
            target->next->prev = NULL;
            rl->root = target->next;
        } else {
            rl->root = NULL;
        }
        return target;
    }
    target->prev->next = target->next;
    if (target->next)
        target->next->prev = target->prev;
    target->next = NULL;
    target->prev = NULL;
    return target;
}


ObjNode *_searchByStr(ObjNode *on, const char *tar)
{
    if (!on) return NULL;
    if (strcmp(on->name, tar) == 0)
        return on;
    return _searchByStr(on->next, tar);
}

ObjNode *searchList(RenderList *rl, const char *tar)
{
    return _searchByStr(rl->root, tar);
}

void compareAndUpdateList(RenderList *dest, RenderList *src)
{
    ObjNode *cur = src->root;
    while (cur) {
        ObjNode *nxt = cur->next;
        if (cur->renderMode == dest->renderMode) {
            if (cur->prev == NULL) {
                if (cur->next) {
                    cur->next->prev = NULL;
                    src->root = cur->next;
                } else {
                    src->root = NULL;
                }
                if (dest->root)
                    dest->root->prev = cur;
                cur->next = dest->root;
                dest->root = cur;
                dest->root->prev = NULL;
            } else {
                cur->prev->next = cur->next;
                if (cur->next)
                    cur->next->prev = cur->prev;
                cur->next = dest->root;
                dest->root = cur;
                dest->root->prev = NULL;
            }
        }
        cur = nxt;
    }
}

void printList(RenderList *rl)
{
    printf("%i %s:\n", rl->renderMode, rl->name);
    _printList(rl->root);
}


void _printList(ObjNode *on)
{
    if (!on) return;
    printf("\t%i %s\n", on->renderMode, on->name);
    _printList(on->next);
}

bool isEmpty(RenderList *rl)
{
    return rl->root == NULL;
}


void _freeNodes(ObjNode *on)
{
    if (!on) return;
    _freeNodes(on->next);
    free(on->name);
    free(on);
}

