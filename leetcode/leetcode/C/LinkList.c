//
//  LinkList.c
//  leetcode
//
//  Created by jueying on 2019/3/13.
//  Copyright © 2019  jueying. All rights reserved.
//

#include "LinkList.h"
#include "CHeader.h"

struct LinkListNode {
	LinkListValue value;
	LinkListNodeRef prev;
	LinkListNodeRef next;
};

unsigned int LKListLength(LinkListNodeRef head)
{
	unsigned length = 0;
	while (head->next != NULL) {
		length++;
		head = head->next;
	}
	
	return length;
}

LinkListNodeRef LKNodeAtIndex(LinkListNodeRef head, unsigned int index)
{
	for (int i = 0; i < index; i++) {
		if (head == NULL) {
			return NULL;
		}
		head = head->next;
	}
	
	return head;
}

LinkListValue LKValueAtIndex(LinkListNodeRef head, unsigned int index)
{
	return LKValueForNode(LKNodeAtIndex(head, index));
}

LinkListValue LKValueForNode(LinkListNodeRef node)
{
	return node->value;
}
