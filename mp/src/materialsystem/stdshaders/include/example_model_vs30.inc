// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// defined $LIGHTING_PREVIEW && defined $FASTPATH && $LIGHTING_PREVIEW && $FASTPATH

#ifndef EXAMPLE_MODEL_VS30_H
#define EXAMPLE_MODEL_VS30_H

#include "shaderapi/ishaderapi.h"
#include "shaderapi/ishadershadow.h"
#include "materialsystem/imaterialvar.h"

class example_model_vs30_Static_Index
{
public:
	example_model_vs30_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
	}

	int GetIndex() const
	{
		return 0;
	}
};

#define shaderStaticTest_example_model_vs30 1


class example_model_vs30_Dynamic_Index
{
	int m_nCOMPRESSED_VERTS : 3;
	int m_nDOWATERFOG : 3;
	int m_nSKINNING : 3;
	int m_nLIGHTING_PREVIEW : 3;
	int m_nNUM_LIGHTS : 4;
#ifdef _DEBUG
	bool m_bCOMPRESSED_VERTS : 1;
	bool m_bDOWATERFOG : 1;
	bool m_bSKINNING : 1;
	bool m_bLIGHTING_PREVIEW : 1;
	bool m_bNUM_LIGHTS : 1;
#endif	// _DEBUG
public:
	void SetCOMPRESSED_VERTS( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nCOMPRESSED_VERTS = i;
#ifdef _DEBUG
		m_bCOMPRESSED_VERTS = true;
#endif	// _DEBUG
	}

	void SetDOWATERFOG( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nDOWATERFOG = i;
#ifdef _DEBUG
		m_bDOWATERFOG = true;
#endif	// _DEBUG
	}

	void SetSKINNING( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nSKINNING = i;
#ifdef _DEBUG
		m_bSKINNING = true;
#endif	// _DEBUG
	}

	void SetLIGHTING_PREVIEW( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nLIGHTING_PREVIEW = i;
#ifdef _DEBUG
		m_bLIGHTING_PREVIEW = true;
#endif	// _DEBUG
	}

	void SetNUM_LIGHTS( int i )
	{
		Assert( i >= 0 && i <= 4 );
		m_nNUM_LIGHTS = i;
#ifdef _DEBUG
		m_bNUM_LIGHTS = true;
#endif	// _DEBUG
	}

	example_model_vs30_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
		m_nCOMPRESSED_VERTS = 0;
		m_nDOWATERFOG = 0;
		m_nSKINNING = 0;
		m_nLIGHTING_PREVIEW = 0;
		m_nNUM_LIGHTS = 0;
#ifdef _DEBUG
		m_bCOMPRESSED_VERTS = false;
		m_bDOWATERFOG = false;
		m_bSKINNING = false;
		m_bLIGHTING_PREVIEW = false;
		m_bNUM_LIGHTS = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bCOMPRESSED_VERTS && m_bDOWATERFOG && m_bSKINNING && m_bLIGHTING_PREVIEW && m_bNUM_LIGHTS );
		return ( 1 * m_nCOMPRESSED_VERTS ) + ( 2 * m_nDOWATERFOG ) + ( 4 * m_nSKINNING ) + ( 8 * m_nLIGHTING_PREVIEW ) + ( 16 * m_nNUM_LIGHTS ) + 0;
	}
};

#define shaderDynamicTest_example_model_vs30 vsh_forgot_to_set_dynamic_COMPRESSED_VERTS + vsh_forgot_to_set_dynamic_DOWATERFOG + vsh_forgot_to_set_dynamic_SKINNING + vsh_forgot_to_set_dynamic_LIGHTING_PREVIEW + vsh_forgot_to_set_dynamic_NUM_LIGHTS


#endif	// EXAMPLE_MODEL_VS30_H