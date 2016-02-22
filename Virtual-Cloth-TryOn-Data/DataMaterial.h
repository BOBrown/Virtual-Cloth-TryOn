#ifndef _VIRTUAL_CLOTH_TRYON_DATA_MATERIAL_H_
#define _VIRTUAL_CLOTH_TRYON_DATA_MATERIAL_H_
#include <iostream>
#include "BaseExport.h"
#include "../dependencies/glm/vec4.hpp"
#define MaxMaterialNameLength 128
#define PI 3.14159265358979323846

class DataTexture;
class CLOTH_DATA_DLL DataMaterial
{
public:
	CString m_strName;        /* name of material */
	glm::vec4 m_Diffuse;       // Kd diffuse component
	glm::vec4 m_Ambient;       // Ka ambient component
	glm::vec4 m_Specular;      // Ks specular component
	glm::vec4 m_Emissive;      // emissive component
	float m_fShininess;        // Ns specular exponent
	float m_fRefraction;       // Tr
	float m_fAlpha;            // d
	float m_fReflectivity;     // reflection

	DataTexture*	m_AmbientMap;
	DataTexture*	m_DiffuseMap;
	DataTexture*	m_SpecularMap;

public:
	DataMaterial();
	~DataMaterial();
public:
	static DataMaterial* LoadMaterialLibrary(CString name, unsigned int& material_number);
};



#endif