#pragma once

#include <windows.h>
#include <string>
#include <list>

//삭제 초기화 
#define SAFE_DELETE(p)	if(p)	{delete p; p = nullptr;}


//화면 너비 높이 
struct Resolution
{
	int Width;
	int Height;
};

struct Vector2D
{
	float	x, y;

	Vector2D() :
		x(0.f),
		y(0.f)
	{
	}

	Vector2D(float _x, float _y) :
		x(_x),
		y(_y)
	{
	}

	Vector2D(const Vector2D& v) :
		x(v.x),
		y(v.y)
	{
	}

	void operator = (const Vector2D& v)
	{
		x = v.x;
		y = v.y;
	}

	void operator = (const POINT& v)
	{
		x = (float)v.x;
		y = (float)v.y;
	}

	Vector2D operator + (const Vector2D& v)	const
	{
		Vector2D	result;

		result.x = x + v.x;
		result.y = y + v.y;

		return result;
	}

	Vector2D operator + (const POINT& v)	const
	{
		Vector2D	result;

		result.x = x + (float)v.x;
		result.y = y + (float)v.y;

		return result;
	}

	Vector2D operator + (float f)	const
	{
		Vector2D	result;

		result.x = x + f;
		result.y = y + f;

		return result;
	}

	void operator += (const Vector2D& v)
	{
		x += v.x;
		y += v.y;
	}

	void operator += (const POINT& v)
	{
		x += (float)v.x;
		y += (float)v.y;
	}

	void operator + (float f)
	{
		x += f;
		y += f;
	}

	Vector2D operator - (const Vector2D& v)	const
	{
		Vector2D	result;

		result.x = x - v.x;
		result.y = y - v.y;

		return result;
	}

	Vector2D operator - (const POINT& v)	const
	{
		Vector2D	result;

		result.x = x - (float)v.x;
		result.y = y - (float)v.y;

		return result;
	}

	Vector2D operator - (float f)	const
	{
		Vector2D	result;

		result.x = x - f;
		result.y = y - f;

		return result;
	}

	void operator -= (const Vector2D& v)
	{
		x -= v.x;
		y -= v.y;
	}

	void operator -= (const POINT& v)
	{
		x -= (float)v.x;
		y -= (float)v.y;
	}

	void operator - (float f)
	{
		x -= f;
		y -= f;
	}

	Vector2D operator * (const Vector2D& v)	const
	{
		Vector2D	result;

		result.x = x * v.x;
		result.y = y * v.y;

		return result;
	}

	Vector2D operator * (const POINT& v)	const
	{
		Vector2D	result;

		result.x = x * (float)v.x;
		result.y = y * (float)v.y;

		return result;
	}

	Vector2D operator * (float f)	const
	{
		Vector2D	result;

		result.x = x * f;
		result.y = y * f;

		return result;
	}

	void operator *= (const Vector2D& v)
	{
		x *= v.x;
		y *= v.y;
	}

	void operator *= (const POINT& v)
	{
		x *= (float)v.x;
		y *= (float)v.y;
	}

	void operator * (float f)
	{
		x *= f;
		y *= f;
	}

	Vector2D operator / (const Vector2D& v)	const
	{
		Vector2D	result;

		result.x = x / v.x;
		result.y = y / v.y;

		return result;
	}

	Vector2D operator / (const POINT& v)	const
	{
		Vector2D	result;

		result.x = x / (float)v.x;
		result.y = y / (float)v.y;

		return result;
	}

	Vector2D operator / (float f)	const
	{
		Vector2D	result;

		result.x = x / f;
		result.y = y / f;

		return result;
	}

	void operator /= (const Vector2D& v)
	{
		x /= v.x;
		y /= v.y;
	}

	void operator /= (const POINT& v)
	{
		x /= (float)v.x;
		y /= (float)v.y;
	}

	void operator / (float f)
	{
		x /= f;
		y /= f;
	}
};