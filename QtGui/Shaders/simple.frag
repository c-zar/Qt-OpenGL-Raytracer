#version 330 core


//TO DO: Write code to compute the reflection vector - GLSL has a function for this.
// Then sample your cube map and update the fragment color.
//Be sure to pass in the correct variables and set your out variables
//-----------------------------------------------------------------------
//in vec4 inColor;
uniform vec4 color;
out vec4 outColor;


void main()
{
    outColor  =  color;
}

//-----------------------------------------------------------------------
