#ifndef _VIRTUAL_CLOTH_TRYON_RENDER_3D_OPERATION_H_
#define _VIRTUAL_CLOTH_TRYON_RENDER_3D_OPERATION_H_

class DataPattern;
class DataCloth;
class DataCamera3D;
class DataMesh;
class DataMaterial;

class ClothRender
{
public:
	void DrawCloth(DataCloth* cloth);
	void DrawPattern(DataPattern* pattern);
	void Render();
	void SetupCamera(DataCamera3D* camera);
	void SetupRender();
	void SetupMaterial(DataMaterial* material);
	void DrawMesh(DataMesh* mesh);
};
#endif