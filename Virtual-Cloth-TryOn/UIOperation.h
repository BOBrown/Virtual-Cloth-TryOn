#ifndef _VIRTUAL_CLOTH_TRYON_UI_OPERATION_H_
#define _VIRTUAL_CLOTH_TRYON_UI_OPERATION_H_
#include "Drawable.h"
#include "../dependencies/glm/vec3.hpp"
class UIOperation :public Drawable
{
protected:
	virtual void		OnLButtonDown(UINT nFlags, glm::vec3);              //When left Button Down,event handler
	virtual void		OnLButtonDblClk(UINT nFlags, glm::vec3);            //When left Button double clicked,event handler
	virtual void		OnLButtonUp(UINT nFlags, glm::vec3);                //When left Button UP,event handler
	virtual void		OnMouseMove(UINT nFlags, glm::vec3);                //When mouse move,event handler
	virtual void		OnRButtonDown(UINT nFlags, glm::vec3);              //When right Button Down,event handler
	virtual void		OnRButtonUp(UINT nFlags, glm::vec3);                //When right Button UP,event handler
	virtual void		OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);        //When Key UP,event handler
	virtual void		OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);      //When Key down,event handler

	virtual void		Draw(CDC* pDC);
};
#endif