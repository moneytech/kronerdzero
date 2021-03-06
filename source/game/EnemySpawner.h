#ifndef __ENEMYSPAWNER_H__
#define __ENEMYSPAWNER_H__

#include <sys/types.h>

#include "SpriteManager.h"

typedef struct {
	int enabled;
	int alive;
	uint64_t nextMove;
	SpriteT *spr;
	int y;
	int ang;
} EnemyT;

void EnemySpawner_init();
void EnemySpawner_update();
int EnemySpawner_enemyCount();
void EnemySpawner_hit(EnemyT *enemy);

#endif
