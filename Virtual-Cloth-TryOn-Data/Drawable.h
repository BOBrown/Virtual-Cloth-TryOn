#ifndef _VIRTUAL_CLOTH_TRYON_DATA_DRAWABLE_OPERATION_H_
#define _VIRTUAL_CLOTH_TRYON_DATA_DRAWABLE_OPERATION_H_
#include "BaseExport.h"
class CDC;
class Drawable
{
public:
	virtual void Draw() = 0;
};
#endif