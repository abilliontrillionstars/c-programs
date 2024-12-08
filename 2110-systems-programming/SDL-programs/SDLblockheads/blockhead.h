void addBlockHeadToList(struct BLOCKHEAD_NODE** blockhead_list);
void removeBlockHeadFromList(struct BLOCKHEAD_NODE** blockhead_list, int index);
void freeBlockHeadList(struct BLOCKHEAD_NODE** blockhead_list);

void renderBlockHead(const struct BLOCKHEAD_NODE blockhead);
void moveBlockHead(struct BLOCKHEAD_NODE* blockhead);
void renderBlockHeadList(const struct BLOCKHEAD_NODE** blockhead_list);
void moveBlockHeadList( struct BLOCKHEAD_NODE** blockhead_list);