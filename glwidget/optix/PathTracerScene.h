#pragma once


#include "Sampler.h"
//#include <optixu/optixu_math_stream_namespace.h>
#include <GLUTDisplay.h>
#include <ObjLoader.h>


//-----------------------------------------------------------------------------
//
// PathTracerScene
//
//-----------------------------------------------------------------------------

class PathTracerScene: public SampleScene
{
public:
	// Set the actual render parameters below in main().
	PathTracerScene()
		: m_rr_begin_depth(1u)
		, m_max_depth(100u)
		, m_sqrt_num_samples( 1u )
		, m_width(512u)
		, m_height(512u)
	{}

	virtual void   initScene( InitialCameraData& camera_data );
	virtual void   trace( const RayGenCameraData& camera_data );
	virtual optix::Buffer getOutputBuffer();

	void   setNumSamples( unsigned int sns )                           { m_sqrt_num_samples= sns; }
	void   setDimensions( const unsigned int w, const unsigned int h ) { m_width = w; m_height = h; }
	void   setMaxDepth( unsigned int depth )                           { m_max_depth= depth; }

	void updateParameter( std::string str, float value);
	float getParameter( std::string str);
	void switchEnvironmentLight( int envId);
	void switchHasHDR( bool hasHDR);
	void updateHasAreaBox( );
	void updateGeometryInstance( );

	unsigned int   m_width;
	unsigned int   m_height;
private:
	// create geometry instances
	std::vector<optix::GeometryInstance> gis0volume;
	std::vector<optix::GeometryInstance> gis1reference;
	std::vector<optix::GeometryInstance> gis2cornell;
	std::vector<optix::GeometryInstance> gis3arealight;

	// Generate material
	optix::Material areaMaterial;
	optix::Material diffuseMaterial;
	optix::Material fogMaterial;
	optix::Material glassMaterial;
	optix::Material mirrorMaterial;

	optix::Program miss_program_noHDR;
	optix::Program miss_program_hasHDR;
	ParallelogramLight light;
	optix::Buffer light_buffer;
	// Should return true if key was handled, false otherwise.
	virtual bool keyPressed(unsigned char key, int x, int y);
	void createEnvironmentScene(int sceneKind);

	optix::GeometryInstance createParallelogram( const float3& anchor,
		const float3& offset1,
		const float3& offset2);

	optix::GeometryInstance PathTracerScene::createSphere( const float3& p, float r);

	//GeometryInstance createLightParallelogram( const float3& anchor,
	//	const float3& offset1,
	//	const float3& offset2,
	//	int lgt_instance = -1);
	optix::GeometryGroup PathTracerScene::createObjloader( const std::string& path, const optix::Matrix4x4 m0,
		const optix::Material &material0);
	void setMaterial( optix::GeometryInstance& gi,
		optix::Material material,
		const std::string& color_name="",
		const float3& color=optix::make_float3(1.f));
	
	optix::Program        m_pgram_bounding_box;
	optix::Program        m_pgram_intersection;

	unsigned int   m_rr_begin_depth;
	unsigned int   m_max_depth;
	unsigned int   m_sqrt_num_samples;
	unsigned int   m_frame;
	unsigned int   m_sampling_strategy;
};


