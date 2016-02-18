#include "stdafx.h"
#include "GLFunction.h"


void GLDrawTriangle()
{
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
	glVertex2f(100.0f, 50.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	glVertex2f(450.0f, 400.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	glVertex2f(450.0f, 50.0f);
	glEnd();
}

void GLDrawLine(glm::vec3 pt1, glm::vec3 pt2)
{
	glBegin(GL_LINES);
	glVertex2f(pt1.x, pt1.y);
	glVertex2f(pt2.x, pt2.y);
	glEnd();
}