#include "Object.h"

Object::Object():pBridge(nullptr), m_bCollision_Check(true){}// Ʈ���� ������ �ٸ� �μ��� ���� �ʱ�ȭ �Ұ�
Object::Object(Transform _info):TransInfo(_info){}
Object::~Object(){}
