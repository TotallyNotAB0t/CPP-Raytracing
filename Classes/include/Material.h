#ifndef RTX_MATERIAL_H
#define RTX_MATERIAL_H

#include "Color.h"

class Material 
{
public:
    Color ka;//ambiant
    Color kd;//diffusion
    Color ks;//specular
    float shininess;

    Material();
    Material(const Color& ka, const Color& kd, const Color& ks, float shininess);
};

#endif //RTX_MATERIAL_H
