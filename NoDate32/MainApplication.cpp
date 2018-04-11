// ヘッダのインクルード
// 独自のヘッダ
#include "MainApplication.h"	// CMainApplication
#include "MainWindow.h"	// CMainWindow
#include "TitleScene.h"	// CTitleScene

// インスタンス初期化関数InitInstance.
BOOL CMainApplication::InitInstance(HINSTANCE hInstance, LPTSTR lpCmdLine, int nShowCmd){

	// ウィンドウクラスの登録.
	CMainWindow::RegisterClass(hInstance);	// CMainWindow::RegisterClassでウィンドウクラス"CMainWindow"を登録.

	// CMainWindowオブジェクトの作成.
	m_pMainWnd = new CMainWindow();	// CMainWindowオブジェクトを作成し, m_pMainWndに格納.

	// ウィンドウの作成.
	if (!m_pMainWnd->Create(_T("NoDate"), WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance)){	// m_pMainWnd->Createでウィンドウ作成(最大化とリサイズを無効化.)し, 失敗した場合.

		// エラー処理
		return FALSE;	// returnでFALSEを返して異常終了.

	}

	// ウィンドウの表示.
	m_pMainWnd->ShowWindow(SW_SHOW);	// m_pMainWnd->ShowWindowで表示.

	// 親のInitInstanceを呼ぶ.
	return CGameApplication::InitInstance(hInstance, lpCmdLine, nShowCmd);	// CGameApplication::InitInstanceを呼ぶ.

}

// ゲームメイン処理関数Main.
int CMainApplication::Main(){

	// 変数の初期化.
	int iRet = 0;	// iRetを0で初期化.
	CScene *pScene = NULL;	// pSceneをNULLで初期化.

	// 生成.
	if (m_iNo == 0 && m_pScene == NULL){	// m_iNoが0で生成されていない時.
		pScene = new CTitleScene(m_pMainWnd, m_pGameTime);	// CTitleSceneを生成し, pSceneに格納.(m_pMainWndとm_pGameTimeを渡す.)
	}

	if (m_pScene == NULL){	// m_pSceneがNULLの時.	
		m_pScene = pScene;	// pSceneを格納.
		if (pScene == NULL){	// pSceneがNULLなら.
			// InitSceneが呼べないので終了.
			return 0;	// 0を返す.
		}
		iRet = m_pScene->InitScene();	// 成功なら0を返す.
		if (iRet == -1){	// -1の時.
			m_pScene->ExitScene();	// 終了処理.
			delete m_pScene;	// m_pSceneを削除.
			m_pScene = NULL;	// NULLをセット.
			m_iNo = -1;	// m_iNoを-1にすることで終了したこと(もうシーン切り替えしないこと)を示す.
			m_pMainWnd->Destroy();	// m_pMainWnd->Destroyでウィンドウを閉じる.
		}
		else{	// 0の時.
			iRet = m_pScene->RunScene();	// 処理中.
			if (iRet == 1){	// 1なら次のシーンへ.
				m_pScene->ExitScene();	// 終了処理.
				delete m_pScene;	// m_pSceneを削除.
				m_pScene = NULL;	// NULLをセット.
				m_iNo++;	// m_iNoをインクリメント.
			}
			else if (iRet == 2){	// 2なら終了.
				m_pScene->ExitScene();	// 終了処理.
				delete m_pScene;	// m_pSceneを削除.
				m_pScene = NULL;	// NULLをセット.
				m_iNo = -1;	// m_iNoを-1にすることで終了したこと(もうシーン切り替えしないこと)を示す.
				m_pMainWnd->Destroy();	// m_pMainWnd->Destroyでウィンドウを閉じる.
			}
		}
	}
	else{	// m_pSceneがNULLでない時.
		iRet = m_pScene->RunScene();	// 処理中.
		if (iRet == 1){	// 1なら次のシーンへ.
			m_pScene->ExitScene();	// 終了処理.
			delete m_pScene;	// m_pSceneを削除.
			m_pScene = NULL;	// NULLをセット.
			m_iNo++;	// m_iNoをインクリメント.
		}
		else if (iRet == 2){	// 2なら終了.
			m_pScene->ExitScene();	// 終了処理.
			delete m_pScene;	// m_pSceneを削除.
			m_pScene = NULL;	// NULLをセット.
			m_iNo = -1;	// m_iNoを-1にすることで終了したこと(もうシーン切り替えしないこと)を示す.
			m_pMainWnd->Destroy();	// m_pMainWnd->Destroyでウィンドウを閉じる.
		}
	}

	// 処理したので0.
	return 0;	// 0を返す.

}