#version 330 core


//TO DO: Write code to compute the reflection vector - GLSL has a function for this.
// Then sample your cube map and update the fragment color.
//Be sure to pass in the correct variables and set your out variables
//-----------------------------------------------------------------------

in vec3 _normal;
in vec3 Coords;
in vec3 cameraPos;

out vec4 outColor;

uniform samplerCube cube_texture;

void main()
{
//    outColor  = vec4(1.0f,1.0f,1.0f,1.0f);
    vec3 viewDir = normalize(Coords - cameraPos);
    vec3 reflectVector = reflect(viewDir, normalize(_normal));
      outColor  = texture(cube_texture, reflectVector);
}

//-----------------------------------------------------------------------
