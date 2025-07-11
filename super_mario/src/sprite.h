#pragma once

struct mainScene;

struct sprite {
	void (*draw)(struct sprite*);
	void (*update)(struct sprite*);
	void (*destroy)(struct sprite*);
	void (*trigger)(struct sprite*, struct sprite*, int,  struct mainScene*);

	int x;
	int y;

	int vx;
	int vy;

	int globalX;
	int globalY;
	int zOrder;

	int width;
	int height;

	bool isCollisionable;
	int collisionDirs;

	int spriteType;
};

void spriteInit(struct sprite* s);
