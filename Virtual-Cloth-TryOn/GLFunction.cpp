#include "stdafx.h"
#include "GLFunction.h"


void GLDrawTriangle()
{
	glDisable(GL_LIGHTING);//记得要关闭光照
	glBegin(GL_TRIANGLES);
	glColor3f(0, 1, 0);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1000.0f, 0.0f);
	glVertex3f(1000.0f, 0.0f, 0.0f);

	glColor3f(1, 0, 0);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1000.0f, 0.0f);
	glVertex3f(-1000.0f, 0.0f, 0.0f);


	glColor3f(0, 0, 1);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1000.0f);
	glVertex3f(1000.0f, 0.0f, 0.0f);


	glEnd();

}

void GLDrawLine(glm::vec3 pt1, glm::vec3 pt2)
{
	glBegin(GL_LINES);
	glVertex2f(pt1.x, pt1.y);
	glVertex2f(pt2.x, pt2.y);
	glEnd();
}