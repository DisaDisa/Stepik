#pragma once
#include <stdlib.h>

int stringStat(const char *string, size_t multiplier, int *count) {
	(*count)++;
	return strlen(string) * multiplier;
}