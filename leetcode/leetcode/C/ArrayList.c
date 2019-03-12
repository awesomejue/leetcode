//
//  ArrayList.c
//  leetcode
//
//  Created by  jueying on 2019/3/12.
//  Copyright © 2019  jueying. All rights reserved.
//

#include "ArrayList.h"
#include "CHeader.h"

int ALArrayResize(ArrayListRef ref, unsigned int length)
{
	if (ref == NULL)
		return 0;
	ref->data = reallocf(ref->data, length * sizeof(ArrayListValue));
	if (ref->data == NULL){
		perror("Fatal error, array resize failed!");
		return 0;
	}
	
	ref->_alloced = length;
	ref->length = ref->length < length ? ref->length : length;
	
	return 1;
}

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

void ALReleaseArray(ArrayListRef ref)
{
	if (ref) {
		free(ref->data);
		free(ref);
	}
}

int ALAppendValue(ArrayListRef ref, ArrayListValue value)
{
	return ALInsertValueAtIndex(ref, value, ref->length);
}

int ALPrePendValue(ArrayListRef ref, ArrayListValue value)
{
	return ALInsertValueAtIndex(ref, value, 0);
}

int ALInsertValueAtIndex(ArrayListRef ref, ArrayListValue value, unsigned int index)
{
	if (index > ref->length) {
		return 0;
	}
	
	if (ref->length + 1 > ref->_alloced) {
		ALArrayResize(ref, ref->_alloced * 2);
	}
	
	memmove(&ref->data[index + 1], &ref->data[index], (ref->length - index) * sizeof(ArrayListValue));
	
	ref->data[index] = value;
	ref->length++;
	
	return 1;
}

void ALRemoveValueWithRange(ArrayListRef ref, unsigned int loc, unsigned int len)
{
	if (loc > ref->length || loc + len > ref->length) {
		return;
	}
	memmove(&ref->data[loc], &ref->data[loc + len],  (ref->length - (loc + len)) * sizeof(ArrayListValue));
	ref->length -= len;
}

void ALRemoveValueAtIndex(ArrayListRef ref, unsigned int index)
{
	ALRemoveValueWithRange(ref, index, 1);
}

int ALValueAtIndex(ArrayListRef ref, unsigned int loc, ArrayListValue *valueRef)
{
	if (loc > ref->length) {
		return 1;
	}
	
	*valueRef = ref->data[loc];
	return 0;
}

int ALIndexOfValue(ArrayListRef ref, ArrayListValue value, ArrayListEqualFunc isEqual)
{
	int i;
	for (i = 0; i < ref->length; i++) {
		if (isEqual(value, ref->data[i]))
			return i;
	}
	
	return -1;
}

void ALRemoveAll(ArrayListRef ref)
{
	ref->length = 0;
}

void ALSort(ArrayListRef ref, ArrayListCompareFunc compare)
{
	
}
