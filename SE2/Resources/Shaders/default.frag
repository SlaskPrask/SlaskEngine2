#version 150
#extension GL_ARB_explicit_attrib_location : enable
  
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    vec4 texel = texture(ourTexture, TexCoord);
    gl_FragColor = texel;
} 