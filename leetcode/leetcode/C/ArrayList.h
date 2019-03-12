//
//  ArrayList.h
//  leetcode
//
//  Created by  jueying on 2019/3/12.
//  Copyright © 2019  jueying. All rights reserved.
//

#ifndef ArrayList_h
#define ArrayList_h

#ifdef __cplusplus
extern "C" {
#endif

typedef void * ArrayListValue;
	
typedef struct {
  
  ArrayListValue *data;
  unsigned int length;
  unsigned int _alloced;
  
} ArrayList, *ArrayListRef;
  
typedef int (*ArrayListEqualFunc)(ArrayListValue value1,
                                    ArrayListValue value2);

typedef int (*ArrayListCompareFunc)(ArrayListValue value1,
                                    ArrayListValue value2);
  
ArrayListRef ALNewArray(unsigned int length);

void ALReleaseArray(ArrayListRef ref);

void ALAppendValue(ArrayListRef ref, ArrayListValue value);

void ALPrePendValue(ArrayListRef ref, ArrayListValue value);

void ALRemoveValueAtIndex(ArrayListRef ref, unsigned int index);

void ALRemoveValueWithRange(ArrayListRef ref, unsigned int loc, unsigned int len);

int ALInsertValueAtIndex(ArrayListRef ref, ArrayListValue value, unsigned int index);

int ALIndexOfValue(ArrayListRef ref, ArrayListValue value, ArrayListEqualFunc isEqual);

void ALRemoveAll(ArrayListRef ref);

void ALSort(ArrayListRef ref, ArrayListCompareFunc compare);
	
#ifdef __cplusplus
}
#endif

#endif /* ArrayList_h */
