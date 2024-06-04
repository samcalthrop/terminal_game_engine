#include "VertexArrayObject.h"

VertexArrayObject::~VertexArrayObject() {
    for (int i=0; i<bufferCount; i++) {
        delete buffers[i];
    }

    delete[] buffers;
}

void VertexArrayObject::bufferData(int attribute, float* data, int count, int stepPerVertex) {
    if (buffers[attribute] == NULL) {
        buffers[attribute] = new DataList(count);

        for (float* i=data; i<data + count; i+=stepPerVertex) {
            buffers[attribute]->bind(i, stepPerVertex);
        }
    } else {
        delete buffers[attribute];
        buffers[attribute] = NULL;
        bufferData(attribute, data, count, stepPerVertex);
    }
}

void VertexArrayObject::bufferIndices(int* indices, int count) {
    if (indexBuffer == NULL) {
        indexBuffer = new int[count];
        indexCount = count;

        for (int i=0; i<count; i++) {
            indexBuffer[i] = indices[i];
        }
    } else {
        delete[] indexBuffer;
        indexBuffer = NULL;
        bufferIndices(indices, count);
    }
}