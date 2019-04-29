#version 150
#extension GL_ARB_explicit_attrib_location : enable
#extension GL_ARB_explicit_uniform_location : enable

layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec2 aTexCoord;
layout (location = 2) uniform mat4 transform;
layout (location = 3) uniform mat4 projection;
layout (location = 4) uniform mat4 camera;

out vec2 TexCoord;

void main()
{
    gl_Position =  projection * camera * transform  * vec4(aPos, 1.0);
    TexCoord = aTexCoord;
}