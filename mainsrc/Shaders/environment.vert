#version 330 core

//TO DO: Set the position of the cubemap and texture coordinates.
// Be sure to pass in the correct variables and set your out variables
//-----------------------------------------------------------------------

layout (location = 0) in vec3 position;

out vec3 TexCoords;

uniform mat4 projection;
uniform mat4 view;

void main()
{
    gl_Position = normalize(projection * view * vec4(position, 1.0f));
    TexCoords = position;
}
//-----------------------------------------------------------------------
