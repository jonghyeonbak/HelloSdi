
// HelloSdiDoc.cpp : CHelloSdiDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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


// CHelloSdiDoc ����/�Ҹ�

CHelloSdiDoc::CHelloSdiDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

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
		AfxMessageBox(_T("���ο� �� ������ �������ϴ�."));
	}

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CHelloSdiDoc serialization

void CHelloSdiDoc::Serialize(CArchive& ar)
{
	// CEditView���� ��� serialization�� ó���ϴ� edit ��Ʈ���� ��� �ֽ��ϴ�.
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

// ����� �׸��� �����մϴ�.
void CHelloSdiDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
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

// �˻� ó���⸦ �����մϴ�.
void CHelloSdiDoc::InitializeSearchContent()
{
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��ü �ؽ�Ʈ ���� �������� �˻� �������� ����մϴ�.
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

// CHelloSdiDoc ����

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


// CHelloSdiDoc ���


BOOL CHelloSdiDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
		if (!CDocument::OnOpenDocument(lpszPathName))
				return FALSE;

		// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
		AfxMessageBox(_T("����ڰ� ������ �������ϴ�."));
		AfxMessageBox(_T("�ΰ��� ���� ��� �ɱ�?"));
		//SetModifiedFlag(true);
		//������ ������ �Ǿ��ٰ� �˷��ִ� â

		return TRUE;
}


void CHelloSdiDoc::OnCloseDocument()
{
		// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

		AfxMessageBox(_T("�̰� �Ƹ� �Ⱥ��ϵ�"));

		CDocument::OnCloseDocument();
}
