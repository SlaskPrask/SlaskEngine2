#version 150
#extension GL_ARB_explicit_attrib_location : enable
#extension GL_ARB_explicit_uniform_location : enable

layout (location = 10) uniform vec3 skin;
in vec2 TexCoord;
uniform sampler2D ourTexture;


void main()
{
	vec4 color = texture(ourTexture, TexCoord);
	vec3 newColor = vec3(color.x * skin.x, color.y * skin.y, color.z * skin.z);
	gl_FragColor = vec4(newColor, color.w);
}
