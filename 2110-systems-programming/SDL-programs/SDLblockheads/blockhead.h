#pragma once

struct BLOCKHEAD_NODE
{
    float x,y; // position
    float dx,dy; // movement component
    long color;
    int size;
    struct BLOCKHEAD_NODE* next;
};


void addBlockHeadToList(struct BLOCKHEAD_NODE** blockhead_list, struct BLOCKHEAD_NODE blockhead);
void removeBlockHeadFromList(struct BLOCKHEAD_NODE** blockhead_list, const int index);
void freeBlockHeadList(struct BLOCKHEAD_NODE** blockhead_list);

void renderBlockHead(const struct BLOCKHEAD_NODE blockhead);
void moveBlockHead(struct BLOCKHEAD_NODE* blockhead);
void renderBlockHeadList(const struct BLOCKHEAD_NODE** blockhead_list);
void moveBlockHeadList( struct BLOCKHEAD_NODE** blockhead_list);