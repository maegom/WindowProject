#pragma once

#include "../GameInfo.h"

class CLevel
{
public:
	CLevel();
	virtual ~CLevel();

protected:
	//객체 저장할 linked list 생성 
	std::list<class CObject*>	mObjList;

public:
	class CObject* FindObject(const char* Name);

public:
	virtual void Init();
	virtual void Input(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);

public:

	//  함수: CreateObj(char*, Vector2D&, Vector2D&)
//
//  용도: 객체 생성
//
//  Pos : 기준점 (x,y)
//  Size : 크기 (x,y) 
//
	template <typename T>
	T* CreateObj(const char* Name, const Vector2D& Pos = Vector2D(0.f, 0.f),
		const Vector2D& Size = Vector2D(100.f, 100.f))
	{
		//객체 동적할당
		T* Obj = new T;

		Obj->SetName(Name); //이름
		Obj->SetPos(Pos);	//시작점
		Obj->SetSize(Size); //크기

		Obj->Init(); //초기화

		//객체 리스트에 저장
		mObjList.push_back((CObject*)Obj);

		return Obj;
	}
};

