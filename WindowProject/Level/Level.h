#pragma once

#include "../GameInfo.h"

class CLevel
{
public:
	CLevel();
	virtual ~CLevel();

protected:
	//��ü ������ linked list ���� 
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

	//  �Լ�: CreateObj(char*, Vector2D&, Vector2D&)
//
//  �뵵: ��ü ����
//
//  Pos : ������ (x,y)
//  Size : ũ�� (x,y) 
//
	template <typename T>
	T* CreateObj(const char* Name, const Vector2D& Pos = Vector2D(0.f, 0.f),
		const Vector2D& Size = Vector2D(100.f, 100.f))
	{
		//��ü �����Ҵ�
		T* Obj = new T;

		Obj->SetName(Name); //�̸�
		Obj->SetPos(Pos);	//������
		Obj->SetSize(Size); //ũ��

		Obj->Init(); //�ʱ�ȭ

		//��ü ����Ʈ�� ����
		mObjList.push_back((CObject*)Obj);

		return Obj;
	}
};

