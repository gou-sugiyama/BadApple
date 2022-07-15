#include "Object.h"

 float abs(void* num) {
		 float buf;
	 if (*(float*)num < 0) {
		 buf = *(float*)num * -1;
	 }
	 else {
		 buf = *(float*)num;
	 }

	 return buf;
 }

//--------------------------
// ”»’è
//--------------------------
bool CheckHit(CObject* pObj1, CObject* pObj2) {
	float distanceX = pObj1->x - pObj2->x;
	float distanceY = pObj1->y - pObj2->y;
	float rangeX = pObj1->rangeX + pObj2->rangeX;
	float rangeY = pObj1->rangeY + pObj2->rangeY;

	if (abs(&distanceX) < rangeX && abs(&distanceY) < rangeY) {
		pObj1->HitAction();
		pObj2->HitAction();
		return true;
	}
	return false;
}

