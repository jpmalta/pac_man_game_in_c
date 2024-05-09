#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"

char** map;
int lines;
int columns;

void readmap() {
	FILE* f;
	f = fopen("map.txt", "r");
	if(f == 0) {
		printf("Error in map scanning");
		exit(1);
	}

	fscanf(f, "%d %d", &lines, &columns);
	allocatemap();
	
	for(int i = 0; i < 5; i++) {
		fscanf(f, "%s", map[i]);
	}

	fclose(f);
}

void allocatemap() {
	map = malloc(sizeof(char*) * lines);

	for(int i = 0; i < lines; i++) {
		map[i] = malloc(sizeof(char) * columns + 1);
	}
}

void freemap() {
	for(int i = 0; i < lines; i++) {
		free(map[i]);
	}

	free(map);
}

int main() {
	
	readmap();

	for(int i = 0; i < lines; i++) {
		printf("%s\n", map[i]);
	}

	freemap();
}