#include "pch.h"
#include <iostream>
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

int main()
{
	int sx, sy, sz, ex, ey, ez;
	scanf_s("%d %d %d %d %d %d", &sx, &sy, &sz, &ex, &ey, &ez);
	int dx, dy, dz, cx, cy, cz;
	if (sx > ex) dx = ex;
	else dx = sx;
	if (sy > ey) dy = ey;
	else dy = sy;
	if (sz > ez) dz = ez;
	else dz = sz;
	if (sx > ex)cx = sx;
	else cx = ex;
	if (sy > ey)cy = sy;
	else cy = ey;
	if (sz > ez) cz = sz;
	else cz = ez;
	BlockID stone = createBlock(BLOCK_STONE);
	int i, j, y, m, n, k, l, a;
	if (cx - dx < cz - dz) {
		if ((cz - dz + 1) % 3 == 0) a = ((cz - dz + 1) / 3) - 1;
		else a = (cz - dz + 1) / 3;
		for (y = 0; y <= cy - dy; y++) {
			for (i = 0; i <= a; i++) {
				locateBlock(stone, dx, dy+y, dz + i);
				locateBlock(stone, dx, dy+y, cz - i);
				locateBlock(stone, cx, dy+y, dz + i);
				locateBlock(stone, cx, dy+y, cz - i);
			}
			for (j = 0; j <= cz - dz; j++) {
				locateBlock(stone, dx + j, dy+y, dz + i - 1 + j);
				locateBlock(stone, dx + j, dy+y, cz - i + 1 - j);
				locateBlock(stone, cx - j, dy+y, dz + i - 1 + j);
				locateBlock(stone, cx - j, dy+y, cz - i + 1 - j);
				if (cz - i + 1 - j - dz - i + 1 - j <= 1) break;
			}
			for (m = 1; m <= (cx - dx + 1) / 6; m++) {
				locateBlock(stone, dx + m, dy+y, dz);
				locateBlock(stone, cx - m, dy+y, dz);
				locateBlock(stone, dx + m, dy+y, cz);
				locateBlock(stone, cx - m, dy+y, cz);
			}
			for (n = 0; n <= cx - dx; n++) {
				locateBlock(stone, dx + m - 1 + n, dy+y, dz + n);
				locateBlock(stone, cx - m + 1 - n, dy+y, dz + n);
				locateBlock(stone, dx + m - 1 + n, dy+y, cz - n);
				locateBlock(stone, cx - m + 1 - n, dy+y, cz - n);
				if (cx - m + 1 - n - dx - m + 1 - n <= 1) break;
			}
			for (k = 1; k < cx - j - dx - j; k++) {
				locateBlock(stone, dx + j + k, cy, dz + i - 1 + j);
				locateBlock(stone, dx + j + k, cy, cz - i + 1 - j);
			}
			for (l = 1; l < cz - n - dz - n; l++) {
				locateBlock(stone, dx + m - 1 + n, cy, dz + n + l);
				locateBlock(stone, cx - m + 1 - n, cy, dz + n + l);
			}
		}
	}
	else {
		if ((cx - dx + 1) % 3 == 0) a = ((cx - dx + 1) / 3) - 1;
		else a = (cx - dx + 1) / 3;
		for (y = 0; y <= cy - dy; y++) {
			for (i = 0; i <= a; i++) {
				locateBlock(stone, dx + i, dy+y, dz);
				locateBlock(stone, cx - i, dy+y, dz);
				locateBlock(stone, dx + i, dy+y, cz);
				locateBlock(stone, cx - i, dy+y, cz);
			}
			for (j = 0; j <= cx - dx; j++) {
				locateBlock(stone, dx + i - 1 + j, dy+y, dz + j);
				locateBlock(stone, cx - i + 1 - j, dy+y, dz + j);
				locateBlock(stone, dx + i - 1 + j, dy+y, cz - j);
				locateBlock(stone, cx - i + 1 - j, dy+y, cz - j);
				if (cx - i + 1 - j - dx - i + 1 - j <= 1) break;
			}
			for (m = 1; m <= (cz - dz + 1) / 6; m++) {
				locateBlock(stone, dx, dy+y, dz + m);
				locateBlock(stone, dx, dy+y, cz - m);
				locateBlock(stone, cx, dy+y, dz + m);
				locateBlock(stone, cx, dy+y, cz - m);
			}
			for (n = 0; n <= cz - dz; n++) {
				locateBlock(stone, dx + n, dy+y, dz + m - 1 + n);
				locateBlock(stone, dx + n, dy+y, cz - m + 1 - n);
				locateBlock(stone, cx - n, dy+y, dz + m - 1 + n);
				locateBlock(stone, cx - n, dy+y, cz - m + 1 - n);
				if (cz - m + 1 - n - dz - m + 1 - n <= 1) break;
			}
			for (k = 1;k<cz-j-dz-j;k++) {
				locateBlock(stone, dx + i - 1 + j, cy, dz + j + k);
				locateBlock(stone, cx - i + 1 - j, cy, dz + j + k);
			}
			for (l = 1; l < cx - n - dx - n; l++) {
				locateBlock(stone, dx + n + l, cy, dz + m - 1 + n);
				locateBlock(stone, dx + n + l, cy, cz - m + 1 - n);
			}
		}
		
	}
}

