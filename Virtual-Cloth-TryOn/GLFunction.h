//opengl图形绘制的实现函数
#ifndef _VIRTUAL_CLOTH_TRYON_GL_FUNCTION_H_
#define _VIRTUAL_CLOTH_TRYON_GL_FUNCTION_H_

#include "gl/GL.h"
#include "gl/GLU.h"
#include "../dependencies/glm/vec3.hpp"

static HGLRC g_GLContext = 0;
void GLDrawTriangle();
void GLDrawLine(glm::vec3 pt1, glm::vec3 pt2);
#endif