//
// Created by albar on 21.09.2017.
//

#include <cstdlib>
#include "init.h"

int clingons = 0;
int ship_x = 0;
int ship_y = 0;

// Local sector objects.
// 0 - space
// 1 - star
// 2 - clingon
// 3 - our ship
// 4 - base
// 5 - warhead

int sector[SECTOR][SECTOR] = { 0 };

// Global galaxy map
// 1 - base
// 2 - ship
// 3 - visited

int init_sector(int stars_min, int stars_max, int clingons_min, int clingon_max, bool base) {

    int j;
    int k;

    srand(time(NULL));

    for (int i = 0; i < SECTOR; i++) {
        for (int j = 0; j < SECTOR; j++) {
            sector[i][j] = 0;
        }
    }

    ship_x = 0;
    ship_y = 0;
    // stars
    for (int i = 1; i <= (rand() % (stars_max - stars_min) + stars_min); i++) {
        do {
            j = rand() % SECTOR;
            k = rand() % SECTOR;
        } while (sector[j][k] != 0);
        sector[j][k] = 1;
    }
    // clingons
    for (int i = 1; i <= (rand() % (clingon_max - clingons_min) + clingons_min); i++) {
        do {
            j = rand() % SECTOR;
            k = rand() % SECTOR;
        } while (sector[j][k] != 0);
        sector[j][k] = 2;
        clingons++;
    }
    // Our ship
    do {
        ship_x = rand() % SECTOR;
        ship_y = rand() % SECTOR;
    } while (sector[ship_x][ship_y] != 0);
    sector[ship_x][ship_y] = 3;
    // 0-1 base
    if (base) {
        do {
            j = rand() % SECTOR;
            k = rand() % SECTOR;
        } while (sector[j][k] != 0);
        sector[j][k] = 4;
    }

    return 0;
}
