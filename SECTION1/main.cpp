#include "defs.h"
#include <iostream>

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Rasteriser.h"
#include "Matrix44.h"
#include "GenericMath.h"
#include "Camera.h"
#include "Loader.h"

#include "ShaderProgram.h"
#include "BasicShader.h"

float angle = 0;

RenderContext* renderContext;
Camera* cam = nullptr;
IndexedModel model;
VertexArrayObject modelVAO(3);

BasicVertexShader vs;
BasicFragmentShader fs;
ShaderProgram shader((VertexShader*)&vs, (FragmentShader*)&fs);

bool renderCB(){
    renderContext->getRasterizer()->clearFrame();

    Matrix44 transformation;
    Matrix44 PVMatrix;
    Matrix44 finalMatrix;

    cam->calculateViewMatrix();

    angle += .005f;

    //make sure you are doing the rotation before the scale!
    transformation.translate(Vector3(0, 0, -3.0f));
    transformation.rotate(Vector3(1, 1, 1).normalise(), angle);
    transformation.scale(Vector3(1, 1, 1));

    //set uniforms
    vs.getUniforms()->set(vs.locationProjectionMatrix, cam->getProjectionMatrix());
    vs.getUniforms()->set(vs.locationViewMatrix, cam->getViewMatrix());
    vs.getUniforms()->set(vs.locationTransformation, transformation);

    //set the location of the light in the shader
    vs.getUniforms()->set(vs.locationLightPosition, Vector3(0, 0, 10));

    //render the object using the shader and the vao
    renderContext->renderIndexedTriangles(shader, modelVAO);

    return true;
}

int main(void){
    if(!loadIndexedModel("res/dome.obj", model)) {
        std::cout << "Failed to load model";
        return -1;
    }

    //load data into VAO
    modelVAO.bufferData(0, model.positions, model.positionsCount, 3);
    modelVAO.bufferData(1, model.uvs, model.uvsCount, 2);
    modelVAO.bufferData(2, model.normals, model.normalsCount, 3);
    modelVAO.bufferIndices(model.indices, model.indexCount);

	initscr();
	raw();
	noecho();
    start_color();
    cbreak();
    curs_set(0);

    renderContext = new RenderContext(WW, WH);
    cam = new Camera();
    cam->createProjection(1.13, (WW / (float)2.0) / (WH), .2f, 400);

    renderContext->getRasterizer()->setRenderCB(renderCB);

    while(true){
        renderContext->getRasterizer()->presentFrame();
        renderContext->getRasterizer()->swapBuffers();

        refresh();
        erase();
    }

    getch();
    clear();

    endwin();

    delete renderContext;
    delete cam;

    return 0;
}