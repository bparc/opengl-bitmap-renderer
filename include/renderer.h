#pragma once
#include <inttypes.h>
#include "renderer_opengl.h"

typedef int32_t bitmap_t;
typedef struct
{
	GLfloat Vertices[(65536 * 2)];
	int32_t Locked;
	int32_t Offset;
	int32_t Viewport[4];
	GLuint VBO;
	GLuint VAO;
#define X 256
#define Y 256
	uint32_t TextureCache[Y * 16][X * 16];//2048
	struct
	{
		int8_t Reserved;
	} CacheRegions[Y][X];
#undef X
#undef Y
	struct
	{
		int32_t Size[2];
		int32_t UV[2];
		double Timestamp;
	} LoadedBitmaps[256];
	int32_t BitmapCount;
	int32_t SetCacheDirty;
	GLuint TextureHandle;
	bitmap_t Font;
	int32_t MemoryInitialized;
	//int32_t BMPLookupTable[1024 * 1024]; // bitmap_t->LoadedBitmaps[int32_t]
} renderer_t;
extern void BeginSubView(renderer_t* state, int32_t viewport[4],int32_t flags);
extern void EndSubView(renderer_t* state);
extern void OutputRenderCommands(renderer_t* state);

extern bitmap_t CreateBitmap(renderer_t* state, const uint32_t* pixels, int32_t x, int32_t y);
extern void GetBitmapSize(renderer_t* state, int32_t* x, int32_t* y, bitmap_t bitmap);

extern void RenderBitmapEx(renderer_t* state, float x, float y, float width, float height,
	float r, float g, float b, float a, float uv_min_x, float uv_min_y,
	float uv_max_x, float uv_max_y, bitmap_t bitmap);
extern void RenderBitmap(renderer_t* state, float x, float y, bitmap_t bitmap);
extern void RenderString(renderer_t* state, const char* string,float x, float y);
extern void RenderRectangle(renderer_t* state, float x, float y, float width, float height,
	float r, float g, float b, float a);