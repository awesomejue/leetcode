//
//  LinkList.h
//  leetcode
//
//  Created by jueying on 2019/3/13.
//  Copyright © 2019  jueying. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#define LIST_NULL ((void *) 0)

typedef void *LinkListValue;

typedef struct LinkListNode *LinkListNodeRef;

LinkListNodeRef LKAppendValue(LinkListNodeRef head, LinkListValue value);

LinkListNodeRef LKPrependValue(LinkListNodeRef head, LinkListValue value);

void LKFreeList(LinkListNodeRef head);

LinkListValue LKValueForNode(LinkListNodeRef node);

void LKSetValueForNode(LinkListNodeRef node, LinkListValue value);

unsigned int LKListLength(LinkListNodeRef head);

LinkListNodeRef LKNodeAtIndex(LinkListNodeRef head, unsigned int index);

LinkListValue LKValueAtIndex(LinkListNodeRef head, unsigned int index);


#endif /* LinkList_h */
