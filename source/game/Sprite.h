#ifndef __SPRITE_H__
#define __SPRITE_H__

#include <sys/types.h>

#define MAX_FRAMES 10

typedef struct {
	int enabled;
	uint8_t *art;
	uint8_t *frames[MAX_FRAMES];
	int frame;
	int nextFrame;
	int width, height;
	int anchorX, anchorY;
	int x, y;
} SpriteT;

void Sprite_init(SpriteT *spr);
void Sprite_animate(SpriteT *spr);
void Sprite_draw(SpriteT *spr, uint8_t *fb);

#endif
