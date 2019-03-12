//
//  ArrayList.c
//  leetcode
//
//  Created by  jueying on 2019/3/12.
//  Copyright © 2019  jueying. All rights reserved.
//

#include "ArrayList.h"
#include "CHeader.h"

static int ALArrayResize(ArrayListRef ref, unsigned int length);

ArrayListRef ALNewArray(unsigned int length)
{
	ArrayListRef ref = malloc(sizeof(ArrayList));
	
	if (ref == NULL)
		return NULL;
	
	ref->data = NULL;
	ref->length = 0;
	ref->_alloced = 0;
	
	ALArrayResize(ref, length);
	
	return ref;
}

static int ALArrayResize(ArrayListRef ref, unsigned int length)
{
	if (ref == NULL)
		return 0;
	
	return 0;
}

void ALReleaseArray(ArrayListRef ref)
{
	
}

void ALAppendValue(ArrayListRef ref, ArrayListValue value)
{
	
}

void ALPrePendValue(ArrayListRef ref, ArrayListValue value)
{
	
}

void ALRemoveValueAtIndex(ArrayListRef ref, unsigned int index)
{
	
}

void ALRemoveValueWithRange(ArrayListRef ref, unsigned int loc, unsigned int len)
{
	
}

int ALInsertValueAtIndex(ArrayListRef ref, ArrayListValue value, unsigned int index)
{
	return 0;
}

int ALIndexOfValue(ArrayListRef ref, ArrayListValue value, ArrayListEqualFunc isEqual)
{
	return 0;
}

void ALRemoveAll(ArrayListRef ref)
{
	
}

void ALSort(ArrayListRef ref, ArrayListCompareFunc compare)
{
	
}
