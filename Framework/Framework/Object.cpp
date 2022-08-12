#include "Object.h"

Object::Object():pBridge(nullptr), m_bCollision_Check(true){}// 트렌스 인포나 다르 인수들 전부 초기화 할것
Object::Object(Transform _info):TransInfo(_info){}
Object::~Object(){}
