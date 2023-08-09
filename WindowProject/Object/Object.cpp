#include "Object.h"

CObject::CObject() :
	mSize(100.f, 100.f),
	mName{},
	mActive(true),
	mMoveSpeed(0.f)
{
}

CObject::CObject(const CObject& obj)
{
}

CObject::~CObject()
{
}

void CObject::Init()
{
}

void CObject::Input(float DeltaTime)
{
}

void CObject::Update(float DeltaTime)
{
	// 이동 방향이 지정되었을 경우 이동시킨다.
	// 만약 D를 눌러서 오른쪽으로 이동시킨다고 가정할 경우
	// mMoveDir의 x값은 1, y값은 0이 나올 것이다.
	// 여기에 mMoveSpeed를 곱하게 되면 mMoveSpeed를 200이라고 가정할 경우
	// 200, 0 이 나오게 될 것이다.
	// 여기에 인자로 들어온 델타타임을 곱해주게 되면 초당 200만큼의 거리를
	// 이동하는 식이 완성된다.
	// 속도 : 200
	//델타타임: 1 / 60
	//
	//200 * (1 / 60)
	//델타타임이 1 / 60 초라면 200을 1초동안 곱했을때 60번 곱하게 되므로 총 누적되는
	//합은 200 / 60 * 60이 되어 200이 나오게 된다.
	mPos += mMoveDir * mMoveSpeed * DeltaTime;
}

void CObject::Collision(float DeltaTime)
{
}

void CObject::Render(HDC hDC)
{
	//사각형 그리기
	Rectangle(hDC, (int)mPos.x, (int)mPos.y, (int)(mPos.x + mSize.x),
		(int)(mPos.y + mSize.y));
	mMoveDir.x = 0.f;
	mMoveDir.y = 0.f;
}
