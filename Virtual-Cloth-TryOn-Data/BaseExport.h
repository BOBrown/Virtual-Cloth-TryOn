#ifdef _CLOTH_DATA_LIB
#define CLOTH_DATA_DLL __declspec(dllexport) 
#else
#define CLOTH_DATA_DLL __declspec(dllimport) 
#endif