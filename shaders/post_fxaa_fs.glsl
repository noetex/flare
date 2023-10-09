#define EDGE_THRESHOLD_MIN 0.0312
#define EDGE_THRESHOLD_MAX 0.125

float rgb2luma(vec3 rgb)
{
    return sqrt(dot(rgb, vec3(0.299, 0.587, 0.114)));
}

vec3 colorCenter = texture(screenTexture,In.uv).rgb;

// Luma at the current fragment
float lumaCenter = rgb2luma(colorCenter);

// Luma at the four direct neighbours of the current fragment.
float lumaDown = rgb2luma(textureOffset(screenTexture,In.uv,ivec2(0,-1)).rgb);
float lumaUp = rgb2luma(textureOffset(screenTexture,In.uv,ivec2(0,1)).rgb);
float lumaLeft = rgb2luma(textureOffset(screenTexture,In.uv,ivec2(-1,0)).rgb);
float lumaRight = rgb2luma(textureOffset(screenTexture,In.uv,ivec2(1,0)).rgb);

// Find the maximum and minimum luma around the current fragment.
float lumaMin = min(lumaCenter,min(min(lumaDown,lumaUp),min(lumaLeft,lumaRight)));
float lumaMax = max(lumaCenter,max(max(lumaDown,lumaUp),max(lumaLeft,lumaRight)));

// Compute the delta.
float lumaRange = lumaMax - lumaMin;

// If the luma variation is lower that a threshold
// (or if we are in a really dark area), we are not
// on an edge, don't perform any AA.
if(lumaRange < max(EDGE_THRESHOLD_MIN,lumaMax*EDGE_THRESHOLD_MAX))\
{
    fragColor = colorCenter;
    return;
}

max(1*0.125,0.0312)
