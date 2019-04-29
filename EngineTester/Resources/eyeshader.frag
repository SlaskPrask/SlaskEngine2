#version 150
#extension GL_ARB_explicit_attrib_location : enable
#extension GL_ARB_explicit_uniform_location : enable

layout (location = 11) uniform vec3 eyes;
in vec2 TexCoord;
uniform sampler2D ourTexture;


void main()
{
	vec4 color = texture(ourTexture, TexCoord);
	vec3 whites = vec3(color.x * 1, color.x * 1, color.x * 1);
	vec3 eyecolor = vec3(color.z * eyes.x, color.z * eyes.y, color.z * eyes.z);
	vec3 brows = vec3(0,0,0);

	gl_FragColor = vec4(whites+eyecolor+brows, color.w);
}