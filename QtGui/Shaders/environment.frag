#version 330 core


//TO DO: Use a sampler object to set the color.
// Be sure to pass in the correct variables and set your out variables
//-----------------------------------------------------------------------

in vec3 TexCoords;

out vec4 fragColor;

uniform samplerCube cube_texture;

void main()
{
    fragColor = texture(cube_texture, TexCoords);
}
//-----------------------------------------------------------------------
