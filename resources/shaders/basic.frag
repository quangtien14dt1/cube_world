#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D tex_sampler;

void main()
{
    vec3 finalColor = texture(tex_sampler, TexCoord).xyz;
	FragColor = vec4(finalColor, 1.0f);
}
