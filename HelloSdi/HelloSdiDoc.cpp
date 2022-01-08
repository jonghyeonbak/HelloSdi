
// HelloSdiDoc.cpp : CHelloSdiDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HelloSdi.h"
#endif

#include "HelloSdiDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHelloSdiDoc

IMPLEMENT_DYNCREATE(CHelloSdiDoc, CDocument)

BEGIN_MESSAGE_MAP(CHelloSdiDoc, CDocument)
END_MESSAGE_MAP()


// CHelloSdiDoc 생성/소멸

CHelloSdiDoc::CHelloSdiDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CHelloSdiDoc::~CHelloSdiDoc()
{
}

BOOL CHelloSdiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	
	if (!m_viewList.IsEmpty())
	{
		reinterpret_cast<CEditView*>(m_viewList.GetHead())->SetWindowText(NULL);
		AfxMessageBox(_T("새로운 빈 문서를 열었습니다."));
	}

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CHelloSdiDoc serialization

void CHelloSdiDoc::Serialize(CArchive& ar)
{
	// CEditView에는 모든 serialization을 처리하는 edit 컨트롤이 들어 있습니다.
	if (!m_viewList.IsEmpty())
	{
		reinterpret_cast<CEditView*>(m_viewList.GetHead())->SerializeRaw(ar);
	}
#ifdef SHARED_HANDLERS

	if (m_viewList.IsEmpty() && ar.IsLoading())
	{
		CFile* pFile = ar.GetFile();
		pFile->Seek(0, FILE_BEGIN);
		ULONGLONG nFileSizeBytes = pFile->GetLength();
		ULONGLONG nFileSizeChars = nFileSizeBytes/sizeof(TCHAR);
		LPTSTR lpszText = (LPTSTR)malloc(((size_t)nFileSizeChars + 1) * sizeof(TCHAR));
		if (lpszText != NULL)
		{
			ar.Read(lpszText, (UINT)nFileSizeBytes);
			lpszText[nFileSizeChars] = '\0';
			m_strThumbnailContent = lpszText;
			m_strSearchContent = lpszText;
		}
	}
#endif
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CHelloSdiDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(m_strThumbnailContent, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CHelloSdiDoc::InitializeSearchContent()
{
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 전체 텍스트 파일 콘텐츠를 검색 콘텐츠로 사용합니다.
	SetSearchContent(m_strSearchContent);
}

void CHelloSdiDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CHelloSdiDoc 진단

#ifdef _DEBUG
void CHelloSdiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHelloSdiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHelloSdiDoc 명령


BOOL CHelloSdiDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
		if (!CDocument::OnOpenDocument(lpszPathName))
				return FALSE;

		// TODO:  여기에 특수화된 작성 코드를 추가합니다.
		AfxMessageBox(_T("사용자가 문서를 열었습니다."));
		AfxMessageBox(_T("두개를 쓰면 어떻게 될까?"));
		//SetModifiedFlag(true);
		//문서가 수정이 되었다고 알려주는 창

		return TRUE;
}


void CHelloSdiDoc::OnCloseDocument()
{
		// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

		AfxMessageBox(_T("이건 아마 안보일듯"));

		CDocument::OnCloseDocument();
}
