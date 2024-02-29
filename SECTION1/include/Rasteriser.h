#ifndef INCLUDE_RASTERISER_H
#define INCLUDE_RASTERISER_H

#include "FrameBuffer.h"
#include "VertexArrayObject.h"
#include "ShaderProgram.h"
#include <thread>

class Vector2;
class Vector3;
class Vector4;
class Matrix44;

class Rasterizer{
    public:
        Rasterizer(int width, int height);
        virtual ~Rasterizer();

        void rasterizeTriangle(const Vector2& v1, const Vector2& v2, const Vector2& v3);

        void presentFrame();

        inline void clearFrame(){
            rFrame->clear(0);
        }

        inline void swapBuffers(){
            currentBuffer ^= 1;
            //presentFrame = frameBuffers[currentBuffer];
            rFrame = frameBuffers[currentBuffer ^ 1];
            pFrame = frameBuffers[currentBuffer];
        }

        inline void setRenderCB(bool(*rendercb)()){
            renderCallback = rendercb;
        }

    private:
        bool(*renderCallback)();
        Framebuffer* pFrame;
        Framebuffer* rFrame;
        Framebuffer* frameBuffers[2];
        int currentBuffer;
        void initializeFramebuffer(int width, int height);
};

class RenderContext {
    public:
        RenderContext(int fbWidth, int fbHeight)
            : r(fbWidth, fbHeight)
        {}

        void renderIndexedTriangles(ShaderProgram& shader, VertexArrayObject& vao);

        Rasterizer* getRasterizer() {
            return &r;
        }

    private:
        Rasterizer r;
};

#endif