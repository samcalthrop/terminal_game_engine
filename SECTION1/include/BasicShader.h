#ifndef INCLUDE_BASIC_SHADERS_H
#define INCLUDE_BASIC_SHADERS_H

#include "VertexShader.h"
#include "FragmentShader.h"

class BasicVertexShader : public VertexShader {
    public:
        int locationProjectionMatrix;
        int locationViewMatrix;
        int locationTransformation;
        int locationLightPosition;

        Vector3 lightPos;
        Matrix44 projectionMatrix, viewMatrix, transformation;
        Matrix44 finalMatrix;

        BasicVertexShader() :
            VertexShader(1000, 1000)
        {}

        virtual void initShader() {
            locationProjectionMatrix = uniforms.bind(projectionMatrix);
            locationViewMatrix = uniforms.bind(viewMatrix);
            locationTransformation = uniforms.bind(transformation);
            locationLightPosition = uniforms.bind(lightPos);
        }

        virtual void prepare() {
            uniforms.get(locationProjectionMatrix, projectionMatrix);
            uniforms.get(locationViewMatrix, viewMatrix);
            uniforms.get(locationTransformation, transformation);
            uniforms.get(locationLightPosition, lightPos);

            finalMatrix = projectionMatrix * viewMatrix * transformation;
        }

        virtual void execute(DataList** attributesIn, DataList* attributesOut, int attributeLocation, Vector4& output) {
            //load attributes
            Vector3 pos, norm;
            Vector2 uv;

            attributesIn[0]->get(attributeLocation, pos);
            attributesIn[1]->get(attributeLocation, uv);
            attributesIn[2]->get(attributeLocation, norm);

            //calculate final vertex position
            output = finalMatrix * Vector4(pos.x, pos.y, pos.z, 1);

            Vector4 translatedNormal = transformation * Vector4(norm.x, norm.y, norm.z, 0);
            Vector4 worldPosition = transformation * Vector4(pos.x, pos.y, pos.z, 1);

            //bind the transformed normal to the output in slot 0
            attributesOut->bind(Vector3(translatedNormal.x, translatedNormal.y, translatedNormal.z)); //will be in attributes(0)

            //bind to position 1, the vector from the world position to the light position
            attributesOut->bind(lightPos - Vector3(worldPosition.x, worldPosition.y, worldPosition.z));
        }
};

class BasicFragmentShader : public FragmentShader {
    public:
        char shades[69] = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,^`'. ";
        int shadesCount = sizeof(shades) / sizeof(shades[0]);

        BasicFragmentShader() :
            FragmentShader(1000)
        {}

        virtual void initShader() { 

        }

        virtual void prepare() {

        }

        virtual char execute(DataList* attributes, Vector4& output) {
            Vector3 surfaceNormal;
            Vector3 toLightVector;

            float brightness;

            attributes->get(0, surfaceNormal);
            attributes->get(1, toLightVector);

            surfaceNormal.normalise();
            toLightVector.normalise();

            brightness = surfaceNormal * toLightVector;
            brightness = MAX(brightness, .19);
            brightness = 1 - brightness;
            brightness *= shadesCount;

            return shades[(int)brightness];
        }
};

#endif