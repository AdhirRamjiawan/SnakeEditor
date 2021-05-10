
#pragma once

const std::string SHADER_FADE_OUT= R"(
	uniform sampler2D texture;

void main()
{
    vec4 pixel = texture2D(texture, gl_TexCoord);

    pixel.r = 0;
    pixel.g = 0;
    pixel.b = 1f;

    gl_FragColor =  pixel;
} 
)";