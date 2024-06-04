#ifndef INCLUDE_SHADER_PROGRAM_H
#define INCLUDE_SHADER_PROGRAM_H

#define NULL 0
#define MAX_VERTEX_PASS_BUFFERS 4

#include "VertexShader.h"
#include "FragmentShader.h"

//binds a vertex shader to a fragment shader allowing the passing of attributes between the two
class ShaderProgram {
    public:
        ShaderProgram(VertexShader* vs, FragmentShader* fs) 
            : vs(vs),
            fs(fs),
            passBuffers(new DataList*[MAX_VERTEX_PASS_BUFFERS])
        {
            vs->initShader();
            fs->initShader();
            
            for (int i=0; i<MAX_VERTEX_PASS_BUFFERS; i++) {
                passBuffers[i] = new DataList(vs->getOutputCount());
            }
        }

        ~ShaderProgram() {
            for (int i=0; i<MAX_VERTEX_PASS_BUFFERS; i++) {
                delete passBuffers[i];
            }

            delete[] passBuffers;
        }

        void prepare() {
            vs->prepare();
            fs->prepare();
        }

        int getPassAttributeCount() {
            return vs->getOutputCount();
        }

        DataList** getPassBuffers() {
            return passBuffers;
        }

        void executeVertexShader(DataList** attributesIn, DataList* attributesOut, int attributeLocation, Vector4& out) {
            vs->execute(attributesIn, attributesOut, attributeLocation, out);
        }

        char executeFragmentShader(DataList* passAttributes, Vector4& out) {
            return fs->execute(passAttributes, out);
        }



    private:
        VertexShader* vs;
        FragmentShader* fs;
        DataList** passBuffers;
};

#endif