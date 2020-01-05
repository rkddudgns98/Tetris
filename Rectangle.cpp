#include "Rectangle.h"



CRectangle::CRectangle()
{
}

CRectangle::~CRectangle()
{
}

bool CRectangle::Init()
{
	if (!CShape::Init()) {

	}

	m_cShape[2][0] = '0';
	m_cShape[2][1] = '0';
	m_cShape[3][0] = '0';
	m_cShape[3][1] = '0';

	m_iWidthCount = 2;

	m_tPivot.x = 1;
	m_tPivot.y = 3;

	return true;
}
