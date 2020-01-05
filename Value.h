#pragma once

#include<iostream>
#include<time.h>
#include"Macro.h"
#include <Windows.h>
#include <list>
#include "flag.h"

using namespace std;

#define STAGE_WIDTH 10
#define STAGE_HEIGHT 15

typedef struct _tagPosition {
	int x;
	int y;

	_tagPosition() :	//생성자
		x(0),	//기본값 0
		y(0)
	{
	}

	_tagPosition(const _tagPosition& pos) {	//복사생성자
		*this = pos;
	}

	_tagPosition(int _x, int _y) :
		x(_x),
		y(_y)
	{
	}

	//Position +
	_tagPosition operator +(const _tagPosition& pos) {
		_tagPosition p;
		p.x = x + pos.x;
		p.y = y + pos.y;
		return p;
	}

	_tagPosition operator +(int i) {
		_tagPosition p;
		p.x = x + i;
		p.y = y + i;
		return p;
	}

	void operator +=(const _tagPosition& pos) {
		x += pos.x;
		y += pos.y;
	}

	void operator +=(int i) {
		x += i;
		y += i;
	}

	//Position -
	_tagPosition operator -(const _tagPosition& pos) {
		_tagPosition p;
		p.x = x - pos.x;
		p.y = y - pos.y;
		return p;
	}

	_tagPosition operator -(int i) {
		_tagPosition p;
		p.x = x - i;
		p.y = y - i;
		return p;
	}

	void operator -=(const _tagPosition& pos) {
		x -= pos.x;
		y -= pos.y;
	}

	void operator -=(int i) {
		x -= i;
		y -= i;
	}
	
	//Position =
	void operator =(const _tagPosition & pos){
		x = pos.x;
		y = pos.y;
	}

}POSITION, *PPOSITION;