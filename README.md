# opengl-bitmap-renderer
A simple OpenGL core profile renderer for 2D pixel-art games that is easy to set up and use.
It automatically caches loaded bitmaps in an internal texture atlas for high-performant rendering.

Sample code:
````C
// Initialization
renderer_t* Ren = (renderer_t*)
malloc(sizeof(*Ren));
memset(Ren, 0, sizeof(*Ren));
// Loading bitmaps
bitmap_t bitmaps[4] = { 0 };
{
uint32_t bitmap[Y][X];
for (int32_t y = 0; y < Y; y++)
{
for (int32_t x = 0; x < X; x++)
{
bitmap[y][x] = 0xff000000;
bitmap[y][x] |= ((rand() % UINT8_MAX) << 0);
bitmap[y][x] |= ((rand() % UINT8_MAX) << 8);
bitmap[y][x] |= ((rand() % UINT8_MAX) << 16);
}
}
bitmaps[0] = CreateBitmap(Ren, &bitmap[0][0], X, Y);
}
// Writing to the vertex stream
BeginSubView(Ren, (int32_t[4]) { 0, 0, 640, 420 }, 0);
RenderRectangle(Ren, 15.0f, 100.0f, 200.0f, 200.0f, 1.0f, 1.0f, 0.0f, 1.0f);
RenderBitmap(Ren, 5.0f, 5.0f, bitmaps[0]);
RenderString(Ren, "Hello,World!", 15.0f, 15.0f);				
EndSubView(Ren);
// Rendering the vertex stream
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0f, 0.0f, 1.0f, 0.0f);
OutputRenderCommands(Ren);
````
