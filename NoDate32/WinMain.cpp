// �w�b�_�̃C���N���[�h
// ����̃w�b�_
#include <tchar.h>		// TCHAR�^
#include <windows.h>	// �W��WindowsAPI

// _tWinMain�֐��̒�`
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd){

	// ���b�Z�[�W�{�b�N�X��"Hello, NoDate!"�̕\��.
	MessageBox(NULL, _T("Hello, NoDate!"), _T("NoDate"), MB_OK);	// MessageBox��"Hello, NoDate!"�ƕ\��.

	// �v���O�����̏I��
	return 0;	// return��0��Ԃ��Đ���I��.

}