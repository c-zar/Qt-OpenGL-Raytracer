#version 330 core

//TO DO: Write code to set the model's position in relation to the view 
//Be sure to pass in the correct variables and set your out variables
//-----------------------------------------------------------------------
in vec3 vertex;
in vec3 normal;

out vec3 _normal;
out vec3 Coords;
out vec3 cameraPos;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;


void main()
{
    cameraPos = transpose(view)[2].xyz;
    _normal = mat3(transpose(inverse(model))) * normal;
    Coords = vec3(model * vec4(vertex, 1.0f));
    gl_Position = normalize(model * inverse(view) * projection * vec4(vertex, 1.0f));
}
//-----------------------------------------------------------------------
