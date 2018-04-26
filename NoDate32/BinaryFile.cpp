// �w�b�_�̃C���N���[�h
// �Ǝ��̃w�b�_
#include "BinaryFile.h"	// CBinaryFile

// �R���X�g���N�^CBinaryFile
CBinaryFile::CBinaryFile() : CFile(){

	// �����o�̏�����
	m_pBytes = NULL;	// m_pBytes��NULL�ɃZ�b�g.
	m_dwSize = 0;		// m_dwSize��0�ɃZ�b�g.

}

// �f�X�g���N�^~CBinaryFile
CBinaryFile::~CBinaryFile() {

	// �t�@�C���ƃo�b�t�@���N���A����.
	Close();	// �t�@�C�������.
	Clear();	// �o�b�t�@��j��.

}

// �w��̃o�C�i���t�@�C����S����ēǂݍ���.
BOOL CBinaryFile::Read(LPCTSTR lpctszFileName) {

	// ��������t�@�C�������, �o�b�t�@���N���A����.
	Close();	// �t�@�C�������.
	Clear();	// �o�b�t�@��j��.

	// �t�@�C���̃I�[�v��
	BOOL bRet = Open(lpctszFileName, GENERIC_READ, OPEN_EXISTING);	// Open�Ŏw��̃t�@�C�����J��.
	if (bRet) {	// ����.

		// �t�@�C���T�C�Y�̎擾.
		DWORD dwSize = GetFileSize(m_hFile, NULL);	// GetFileSize�ŃT�C�Y���擾��, dwSize�Ɋi�[.

		// �o�b�t�@�̍쐬.
		m_pBytes = new BYTE[dwSize + 1];	// new��dwSize + 1�̃o�C�g����쐬��, �|�C���^��m_pBytes�Ɋi�[.
		ZeroMemory(m_pBytes, dwSize + 1);	// ZeroMemory��m_pBytes��(dwSize + 1)��, 0�Ŗ��߂�.

		// �t�@�C���̓ǂݍ���.
		m_dwSize = CFile::Read(m_pBytes, dwSize);	// CFile::Read�Ńf�[�^��ǂݍ���.
		if (m_dwSize == dwSize) {	// �S�ēǂݍ��߂���.
			return TRUE;	// ����.
		}

	}

	// ���s.
	return FALSE;	// FALSE��Ԃ�.

}

// �w��̃o�C�i���t�@�C�����w��̈ʒu����w��̃T�C�Y���ǂݍ���.
BOOL CBinaryFile::Read(LPCTSTR lpctszFileName, DWORD dwStart, DWORD dwSize){

	// ��������t�@�C�������, �o�b�t�@���N���A����.
	Close();	// �t�@�C�������.
	Clear();	// �o�b�t�@��j��.

	// �t�@�C���̃I�[�v��
	BOOL bRet = Open(lpctszFileName, GENERIC_READ, OPEN_EXISTING);	// Open�Ŏw��̃t�@�C�����J��.
	if (bRet) {	// ����.

		// �t�@�C���|�C���^�̈ړ�.
		SetFilePointer(m_hFile, (LONG)dwStart, NULL, FILE_BEGIN);	// SetFilePointer��dwStart�̈ʒu�܂ňړ�.

		// �o�b�t�@�̍쐬.
		m_pBytes = new BYTE[dwSize + 1];	// new��dwSize + 1�̃o�C�g����쐬��, �|�C���^��m_pBytes�Ɋi�[.
		ZeroMemory(m_pBytes, dwSize + 1);	// ZeroMemory��m_pBytes��(dwSize + 1)��, 0�Ŗ��߂�.

		// �t�@�C���̓ǂݍ���.
		m_dwSize = CFile::Read(m_pBytes, dwSize);	// CFile::Read�Ńf�[�^��ǂݍ���.
		if (m_dwSize == dwSize) {	// �S�ēǂݍ��߂���.
			return TRUE;	// ����.
		}

	}

	// ���s.
	return FALSE;	// FALSE��Ԃ�.

}

// �ȑO�̃t�@�C���ňȑO�ǂݍ��񂾌�̈ʒu����w��̃T�C�Y��ǂݍ���.
BOOL CBinaryFile::Read(DWORD dwSize){

	// �t�@�C�����J���Ă��Ȃ��ꍇ�̓G���[, �J���Ă���ꍇ�ǂݍ���.
	if (m_tstrFileName.c_str() == _T("") && m_hFile == NULL) {
		return FALSE;	// �t�@�C�����J���Ă��Ȃ��ꍇ��FALSE��Ԃ�.
	}
	else {	// �t�@�C�����J���Ă���ꍇ.

		// �o�b�t�@��j��.
		Clear();	// �o�b�t�@��j��.

		// �o�b�t�@�̍쐬.
		m_pBytes = new BYTE[dwSize + 1];	// new��dwSize + 1�̃o�C�g����쐬��, �|�C���^��m_pBytes�Ɋi�[.
		ZeroMemory(m_pBytes, dwSize + 1);	// ZeroMemory��m_pBytes��(dwSize + 1)��, 0�Ŗ��߂�.

		// �t�@�C���̓ǂݍ���.
		m_dwSize = CFile::Read(m_pBytes, dwSize);	// CFile::Read�Ńf�[�^��ǂݍ���.
		if (m_dwSize == dwSize) {	// �S�ēǂݍ��߂���.
			return TRUE;	// ����.
		}
		
	}

	// ���s.
	return FALSE;	// FALSE��Ԃ�.

}

// �w��̃o�C�i���t�@�C���ɑS����ď�������.
BOOL CBinaryFile::Write(LPCTSTR lpctszFileName) {

	// �t�@�C���̃I�[�v��
	BOOL bRet = Open(lpctszFileName, GENERIC_WRITE, CREATE_ALWAYS);	// Open�Ŏw��̃t�@�C�����J��.
	if (bRet) {	// ����.

		// �t�@�C���̏�������.
		CFile::Write(m_pBytes, m_dwSize);	// CFile::Write�Ńf�[�^����������.

	}

	// bRet�Ő������ǂ������킩��.
	return bRet;	// bRet��Ԃ�.

}

// �J���Ă���o�C�i���t�@�C���ւ̒ǉ���������.
BOOL CBinaryFile::Write() {

	// �����Ȃ��o�[�W������, ���Ƀt�@�C�����J���Ă���O���, Set�ŐV���Ƀo�b�t�@�ɃZ�b�g�����o�C�g����p�����ď�������.
	if (m_tstrFileName.c_str() == _T("") && m_hFile == NULL) {
		return FALSE;	// �t�@�C�����J���Ă��Ȃ��ꍇ��FALSE��Ԃ�.
	}
	else {	// �t�@�C�����J���Ă���ꍇ.
		CFile::Write(m_pBytes, m_dwSize);	// CFile::Write�Ńf�[�^����������.
		return TRUE;	// �������񂾂̂�TRUE.
	}

}

// �S����Ăɏ������ރo�b�t�@�̃Z�b�g.
void CBinaryFile::Set(BYTE * pBytes, DWORD dwSize) {

	// �o�b�t�@���N���A����.
	Clear();	// �o�b�t�@��j��.

	// �����o�ɃZ�b�g.
	m_dwSize = dwSize;	// m_dwSize��dwSize���Z�b�g.

	// �o�b�t�@�̍쐬.
	m_pBytes = new BYTE[m_dwSize + 1];	// new��m_dwSize + 1�̃o�C�g����쐬��, �|�C���^��m_pBytes�Ɋi�[.
	ZeroMemory(m_pBytes, m_dwSize + 1);	// ZeroMemory��m_pBytes��(m_dwSize + 1)��, 0�Ŗ��߂�.

	// �f�[�^�̃R�s�[.
	CopyMemory(m_pBytes, pBytes, m_dwSize);	// CopyMemory�ŃR�s�[.

}

// �o�b�t�@�̃N���A.
void CBinaryFile::Clear() {

	// �o�b�t�@�̔j��.
	if (m_pBytes != NULL) {	// �o�b�t�@���c���Ă�����.
		delete[] m_pBytes;	// delete[]��m_pBytes�����.
		m_pBytes = NULL;	// m_pBytes��NULL���Z�b�g.
	}
	m_dwSize = 0;	// �T�C�Y��0�ɂ���.

}