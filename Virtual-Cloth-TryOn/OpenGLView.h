#ifndef _VIRTUAL_CLOTH_TRYON_GL_VIEW_H_
#define _VIRTUAL_CLOTH_TRYON_GL_VIEW_H_
#include "../dependencies/glm/vec3.hpp"

class OpenGLView :public CView
{
public:
	OpenGLView() :CView()
	{

	}
	~OpenGLView(){}
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
public:
	BOOL SetWindowPixelFormat();
	BOOL SceneBegin();
	BOOL SceneEnd();
	BOOL SceneFlip();
protected:
	glm::vec3 point_to_vec3(CPoint point);
protected:
	DECLARE_MESSAGE_MAP()

};
#endif