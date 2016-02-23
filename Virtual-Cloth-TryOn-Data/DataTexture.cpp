#include "stdafx.h"
#include "DataTexture.h"
#include "atlimage.h"
#include "../dependencies/include/gl/GL.h"
#include "assert.h"
//#include "HouseData/DataUtils.h"
//#include "../HouseDesign/resource.h"
DataTexture::DataTexture()
{

}
DataTexture* DataTexture::LoadTexture(CString file_name)
{
	CImage image;
	HRESULT hr = image.Load(file_name);
	if (!SUCCEEDED(hr))
	{
		CString message;
		//message.Format(IDS_FILE_NOT_FOUND);
		//message.Format(message, file_name);
		//utilMessageBox(message);
		return NULL;
	}

	GLuint texture_id;
	glGenTextures(1, &texture_id);
	glBindTexture(GL_TEXTURE_2D, texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* data = (unsigned char*)image.GetBits();
	int imageBPP = image.GetBPP();
	data += (image.GetHeight() - 1)*image.GetPitch();
	if (imageBPP == 32)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.GetWidth(), image.GetHeight(), 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, data);
	}
	else if (imageBPP == 24)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.GetWidth(), image.GetHeight(), 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
	}
	else
	{
		assert(false);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	assert(glGetError() == 0);

	DataTexture* texture = new DataTexture;
	texture->m_iHeight = image.GetHeight();
	texture->m_iWidth = image.GetWidth();
	texture->m_strName = file_name;
	texture->m_iTextureID = texture_id;

	return texture;
}