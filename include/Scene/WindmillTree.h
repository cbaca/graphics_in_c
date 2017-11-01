#ifndef WINDMILLSCENE_H
#define WINDMILLSCENE_H
#include "SceneTreeNode.h"
#include <stdbool.h>

typedef struct WMTree {
    SceneTreeNode *root;
    Vec3 angles;
    size_t numNodes;
    bool bodySpinFlag;
    bool bladeSpinFlag;
} WMTree;

WMTree *newWindmillTree(BufferData *data, Vec3 *pos, float size);
void destroyWindmillTree(WMTree *wm);
void drawWindmillTree(WMTree *wm, GLint uModel, GLint uColor);
void updateWindmillTree(WMTree *wm, bool f1, bool f2);
void updateWindmillMatrices(WMTree *wm);
void checkWindmillTreeHL(WMTree *wm);
#endif /* WINDMILLSCENE_H */
