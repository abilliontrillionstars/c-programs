#include <stdlib.h>
#include "blockhead.h"


void addBlockHeadToList(struct BLOCKHEAD_NODE** blockhead_list, struct BLOCKHEAD_NODE blockhead)
{
    //note that we pass by value so we can offload the mallocking/copying here
    struct BLOCKHEAD_NODE* node = (struct BLOCKHEAD_NODE*)malloc(sizeof(struct BLOCKHEAD_NODE));
    *node = blockhead;
    // go to the tail of the linkedlist if we're not there already
    while((*blockhead_list)->next != NULL)
        *blockhead_list = (*blockhead_list)->next;
    // *now* set the tail's next
    (*blockhead_list)->next = node;
}
void removeBlockHeadFromList(struct BLOCKHEAD_NODE** blockhead_list, const int index)
{
    for(int i=0; i<index; i++)
        if((*blockhead_list)->next == NULL)
            return;
        else
           *blockhead_list = (*blockhead_list)->next;    
}
void freeBlockHeadList( struct BLOCKHEAD_NODE** blockhead_list)
{
    //this function will free all of the blockhead nodes in the list.
}


void renderBlockHead(const struct BLOCKHEAD_NODE blockhead)
{
    //this function should draw the blockhead according that is appropriate for the structure elements.
}
void moveBlockHead(struct BLOCKHEAD_NODE* blockhead)
{
    //this function should use the displacement vector to move the blockhead to a new position..
    //Be sure to handle bouncing off of the window borders.
}
void renderBlockHeadList(const struct BLOCKHEAD_NODE** blockhead_list)
{
    //this function should render all of the items in the block head list.
}
void moveBlockHeadList( struct BLOCKHEAD_NODE** blockhead_list)
{
    //this function should update all of the items in the block head list.
}