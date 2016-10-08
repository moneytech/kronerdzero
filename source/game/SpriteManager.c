
#include "SpriteManager.h"
#include "memory.h"

void
SpriteManager_init() {
	for ( int i = 0; i < MAX_SPRITE; i++ ) {
		sprites[i].enabled = 0;
	}
}

SpriteT *
SpriteManager_newSprite() {
	for ( int i = 0; i < MAX_SPRITE; i++ ) {
		if ( ! sprites[i].enabled ) {
			Sprite_init(&sprites[i]);
			return &sprites[i];
		}
	}
	return NULL;
}

void
SpriteManager_draw(uint8_t *fb) {
	for ( int i = 0; i < MAX_SPRITE; i++ ) {
		if ( sprites[i].enabled ) {
			Sprite_animate(&sprites[i]);
			Sprite_draw(&sprites[i], fb);
		}
	}
}