//
//  main.cpp
//  leetcode
//
//  Created by  jueying on 2019/3/11.
//  Copyright © 2019  jueying. All rights reserved.
//

#include "STLHeader.h"
#include <string>

#include <thread>
#include <memory>

#include "ArrayList.h"

int main(int argc, const char * argv[]) {
	// insert code here...
	
	ArrayListRef array = ALNewArray(1);
	
	char string[] = "abcdefghijk";

	for (int i = 0; i < strlen(string); i++) {
		ALAppendValue(array, string + i);
	}
	
	for (int i = 0; i < 5; i++) {
		ALRemoveValueAtIndex(array, array->length - 1);
	}
	
	for (int i = 0; i < array->length; i++) {
		printf("%c", *(char *)array->data[i]);
	}
	
	function<double(double)> foo = sqrt;
	
	return 0;
}
