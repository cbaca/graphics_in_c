#ifndef HLINKEDLIST_H
#define HLINKEDLIST_H
#include "types.h"


struct hlist {
    hnode *first;
};

struct hnode {
    struct hnode *next, **prev;
};

#define HLIST_HEAD_INIT { .first = NULL }
#define HLIST_HEAD(name) struct hlist_head name = {  .first = NULL }
#define INIT_HLIST_HEAD(ptr) ((ptr)->first = NULL)
static inline void
INIT_HLIST_NODE(struct hnode *h)
{
    h->next = nil;
    h->pprev = nil;
}

static inline bool_t
hlist_unhashed(const struct hnode *h)
{
    return !h->pprev;
}

static inline bool_t
hlist_empty(const struct hlist_head *h)
{
    return !h->first;
}

static inline void
__hlist_del(struct hnode *n)
{
    struct hnode *next = n->next;
    struct hnode **pprev = n->pprev;

    *pprev = next;
    if (next)
        next->pprev = pprev;
}

static inline void
hlist_del(struct hnode *n)
{
    __hlist_del(n);
    n->next = nil;
    n->pprev = nil;
}

static inline void
hlist_del_init(struct hnode *n)
{
    if (!hlist_unhashed(n)) {
        __hlist_del(n);
        n->next = nil;
        n->pprev = nil;
    }
}

static inline void
hlist_add_head(struct hnode *n, struct hlist_head *h)
{
    struct hnode *first = h->first;
    n->next = first;
    if (first)
        first->pprev = &n->next;
    h->first = n;
    n->pprev = &h->first;
}

/* next must be != NULL */
static inline void
hlist_add_before(struct hnode *n, struct hnode *next)
{
    n->pprev = next->pprev;
    n->next = next;
    next->pprev = &n->next;
    *(n->pprev) = n;
}

static inline void
hlist_add_behind(struct hnode *n, struct hnode *prev)
{
    n->next = prev->next;
    prev->next = n;
    n->pprev = &prev->next;

    if (n->next)
        n->next->pprev  = &n->next;
}

/* after that we'll appear to be on some hlist and hlist_del will work */
static inline void
hlist_add_fake(struct hnode *n)
{
    n->pprev = &n->next;
}

static inline bool_t
hlist_fake(struct hnode *h)
{
    return h->pprev == &h->next;
}

/*
 * Check whether the hnode is the only hnode of the head without
 * accessing head:
 */
static inline bool_t
hlist_is_singular_hnode(struct hnode *n, struct hlist_head *h)
{
    return !n->next && n->pprev == &h->first;
}

/*
 * Move a list from one list head to another. Fixup the pprev
 * reference of the first entry if it exists.
 */
static inline void
hlist_move_list(struct hlist_head *old, struct hlist_head *new)
{
    new->first = old->first;
    if (new->first)
        new->first->pprev = &new->first;
    old->first = NULL;
}

#define hlist_entry(ptr, type, member) container_of(ptr,type,member)

#define hlist_for_each(pos, head) \
    for (pos = (head)->first; pos ; pos = pos->next)

#define hlist_for_each_safe(pos, n, head) \
    for (pos = (head)->first; pos && ({ n = pos->next; 1; }); \
         pos = n)

#define hlist_entry_safe(ptr, type, member) \
    ({ typeof(ptr) ____ptr = (ptr); \
       ____ptr ? hlist_entry(____ptr, type, member) : NULL; \
    })

/**
 * hlist_for_each_entry    - iterate over list of given type
 * @pos:    the type * to use as a loop cursor.
 * @head:    the head for your list.
 * @member:    the name of the hnode within the struct.
 */
#define hlist_for_each_entry(pos, head, member)                \
    for (pos = hlist_entry_safe((head)->first, typeof(*(pos)), member);\
         pos;                            \
         pos = hlist_entry_safe((pos)->member.next, typeof(*(pos)), member))

/**
 * hlist_for_each_entry_continue - iterate over a hlist continuing after current point
 * @pos:    the type * to use as a loop cursor.
 * @member:    the name of the hnode within the struct.
 */
#define hlist_for_each_entry_continue(pos, member)            \
    for (pos = hlist_entry_safe((pos)->member.next, typeof(*(pos)), member);\
         pos;                            \
         pos = hlist_entry_safe((pos)->member.next, typeof(*(pos)), member))

/**
 * hlist_for_each_entry_from - iterate over a hlist continuing from current point
 * @pos:    the type * to use as a loop cursor.
 * @member:    the name of the hnode within the struct.
 */
#define hlist_for_each_entry_from(pos, member)                \
    for (; pos;                            \
         pos = hlist_entry_safe((pos)->member.next, typeof(*(pos)), member))

/**
 * hlist_for_each_entry_safe - iterate over list of given type safe against removal of list entry
 * @pos:    the type * to use as a loop cursor.
 * @n:        another &struct hnode to use as temporary storage
 * @head:    the head for your list.
 * @member:    the name of the hnode within the struct.
 */
#define hlist_for_each_entry_safe(pos, n, head, member)         \
    for (pos = hlist_entry_safe((head)->first, typeof(*pos), member);\
         pos && ({ n = pos->member.next; 1; });            \
         pos = hlist_entry_safe(n, typeof(*pos), member))


#endif /* LINKED_LIST_H */
