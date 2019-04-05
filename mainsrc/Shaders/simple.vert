#version 330 core

//TO DO: Write code to set the model's position in relation to the view 
//Be sure to pass in the correct variables and set your out variables
//-----------------------------------------------------------------------
in vec3 vertex;

void main()
{
    gl_Position = normalize(vec4(vertex, 1.0f));
}
//-----------------------------------------------------------------------
