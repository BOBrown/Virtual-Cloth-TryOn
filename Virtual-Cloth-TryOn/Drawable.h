#ifndef _VIRTUAL_CLOTH_TRYON_DRAWABLE_OPERATION_H_
#define _VIRTUAL_CLOTH_TRYON_DRAWABLE_OPERATION_H_
class CDC;
class Drawable
{
public:
	virtual void Draw(CDC* pDC) = 0;
};
#endif