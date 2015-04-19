#ifndef _RAY_CUH_
#define _RAY_CUH_

#include "helpers.h"
//#include <optix.h>
//#include <optixu/optixu_math_namespace.h>

using namespace optix;


rtDeclareVariable(float,        isSingle, , );
struct PerRayData_pathtrace
{
	float3 result;
	float3 radiance;
	float3 attenuation;
	float3 origin;
	float3 direction;
	unsigned int seed;
	int depth;
	int countEmitted;
	int done;
	int inside;
	int inside2;//for glass in fog
	int insertedDiffuse;
};

struct PerRayData_pathtrace_shadow
{
	unsigned int seed;
	float3 origin;
	float3 direction;
	float3 attenuation;
};

// Scene wide
rtDeclareVariable(float,         scene_epsilon, , );
rtDeclareVariable(rtObject,      top_object, , );
rtBuffer<ParallelogramLight>     lights;
rtDeclareVariable(float,         light_em, , );

rtDeclareVariable(unsigned int,  pathtrace_ray_type, , );
rtDeclareVariable(unsigned int,  pathtrace_shadow_ray_type, , );
rtDeclareVariable(unsigned int,  rr_begin_depth, , );
rtDeclareVariable(unsigned int,  maxDepth, , );

rtDeclareVariable(float3, geometric_normal, attribute geometric_normal, ); 
rtDeclareVariable(float3, shading_normal,   attribute shading_normal, ); 

rtDeclareVariable(PerRayData_pathtrace, current_prd, rtPayload, );

rtDeclareVariable(optix::Ray, ray,          rtCurrentRay, );
rtDeclareVariable(float,      t_hit,        rtIntersectionDistance, );

// For miss program
rtDeclareVariable(float3,       bg_color, , );
rtDeclareVariable(float3,        bad_color, , );
// For shadow program
rtDeclareVariable(PerRayData_pathtrace_shadow, current_prd_shadow, rtPayload, );

#endif