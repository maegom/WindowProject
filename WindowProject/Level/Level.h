#pragma once

#include "../GameInfo.h"

class CLevel
{
public:
	CLevel();
	virtual ~CLevel();

protected:
	std::list<class CObject*>	mObjList;

public:
	virtual void Init();
	virtual void Input(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);

public:
	template <typename T>
	T* CreateObj(const char* Name, const Vector2D& Pos = Vector2D(0.f, 0.f),
		const Vector2D& Size = Vector2D(100.f, 100.f))
	{
		T* Obj = new T;

		Obj->SetName(Name);
		Obj->SetPos(Pos);
		Obj->SetSize(Size);

		Obj->Init();

		mObjList.push_back((CObject*)Obj);

		return Obj;
	}
};

