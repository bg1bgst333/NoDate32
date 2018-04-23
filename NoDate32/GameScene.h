// ��d�C���N���[�h�h�~
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "Scene.h"	// CScene
#include "SharedObject.h"	// CSharedObject

// �O���錾.
class CSharedObject;	// CSharedObject.

// �Q�[���V�[���N���XCGameScene
class CGameScene : public CScene{

	// public�����o
	public:

		// public�����o�ϐ�
		CSharedObject *m_pSharedObject1;	// CSharedObject�I�u�W�F�N�g�|�C���^m_pSharedObject1.
		CSharedObject *m_pSharedObject2;	// CSharedObject�I�u�W�F�N�g�|�C���^m_pSharedObject2.
		CSharedObject *m_pSharedObject3;	// CSharedObject�I�u�W�F�N�g�|�C���^m_pSharedObject3.

		// �R���X�g���N�^�E�f�X�g���N�^
		CGameScene();	// �R���X�g���N�^CGameScene
		CGameScene(const CWindow *pWnd);	// �R���X�g���N�^CGameScene(const CWindow *pWnd)
		CGameScene(const CWindow *pWnd, CGameTime *pTime);	// �R���X�g���N�^CGameScene(const CWindow *pWnd, CGameTime *pTime)
		CGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem);	// �R���X�g���N�^CGameScene(const CWindow *pWnd, CGameTime *pTime, CGameSystem *pSystem)
		virtual ~CGameScene();	// �f�X�g���N�^~CGameScene
		virtual int InitGameObjects();	// �Q�[���I�u�W�F�N�g�̏�����.
		virtual int InitKeyboard();	// �L�[�{�[�h�̏�����.
		virtual int CheckKeyboard();	// �L�[�{�[�h�̃`�F�b�N.
		virtual int RunProc();	// �L�[���͂⎞�ԂȂǂ��珈�����v�Z.
		virtual int DrawGameObjects();	// �Q�[���I�u�W�F�N�g�̕`��.
		virtual int ExitGameObjects();	// �Q�[���I�u�W�F�N�g�̏I������.

};

#endif